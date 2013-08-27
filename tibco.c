/* ***********************IMPORTANT ***************************************
 *  Copyright (C) 2006 Lukas Prettenthaler <http://zyclonite.net>         *
 *  This program is free software; you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation; either version 2 of the License.        *
 *                                                                        *
 *                      ********************                              *
 *                                                                        *
 *  This program is distributed in the hope that it will be useful,       *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *  GNU Library General Public License for more details.                  *
 *                                                                        *
 *                      ********************                              *
 *                                                                        *
 * You are highly encouraged to send your changes to <rdx@wsn.at>         *
 * for possible incorporation into the main distribution.                 *
 * By sending these changes to <rdx@wsn.at>, it is assumed                *
 * that you are offering <rdx@wsn.at> the unlimited,                      *
 * non-exclusive right to reuse, modify, and relicense the code.          *
 **************************************************************************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_tibco.h"
#include "tibemsUtilities.h"

static function_entry tibco_functions[] = {
    PHP_FE(tibco_version, NULL)
    PHP_FE(tibco_sendmsg, NULL)
    PHP_FE(tibco_recvmsg, NULL)
    PHP_FE(tibco_connect, NULL)
    PHP_FE(tibco_disconnect, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry tibco_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_TIBCO_EXTNAME,
    tibco_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_TIBCO_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_TIBCO
ZEND_GET_MODULE(tibco)
#endif

tibemsConnection   connection   = NULL;
tibemsSession      session      = NULL;
tibemsMsgProducer  msgProducer  = NULL;
tibemsDestination  destination  = NULL;
tibemsMsgConsumer  msgConsumer  = NULL;

tibems_status      status       = TIBEMS_OK;
tibemsSSLParams    sslParams    = NULL;

void fail(const char* message, tibems_status s)
{
    const char* msg = tibemsStatus_GetText(s);
    php_error_docref(NULL TSRMLS_CC, E_ERROR, "%s",message);
    php_error_docref(NULL TSRMLS_CC, E_ERROR, "STATUS: %d %s\n",s,msg?msg:"(Undefined Error)");
    exit(1);
}

void onException(
    tibemsConnection    conn,
    tibems_status       reason,
    void*               closure)
{
    /* print the connection exception status */

    if (reason == TIBEMS_SERVER_NOT_CONNECTED)
    {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "CONNECTION EXCEPTION: Server Disconnected\n");
        exit(1);
    }
}

PHP_MSHUTDOWN_FUNCTION(tibco)
{
    /* close the connection */
    status = tibemsConnection_Close(connection);
    if (status != TIBEMS_OK)
    {
        fail("Error closing tibemsConnection", status);
    }

    /* destroy the ssl params */
    tibemsSSLParams_Destroy(sslParams);

    UNREGISTER_INI_ENTRIES();

    return SUCCESS;
}

PHP_MINFO_FUNCTION(tibco)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "tibco jms support", "enabled");
	php_info_print_table_row(2, "Version", PHP_TIBCO_VERSION);
	php_info_print_table_end();
}

PHP_FUNCTION(tibco_version)
{
    RETURN_STRING(PHP_TIBCO_VERSION, 1);
}

PHP_FUNCTION(tibco_disconnect)
{
    /* close the connection */
    status = tibemsConnection_Close(connection);
    if (status != TIBEMS_OK)
    {
        fail("Error closing tibemsConnection", status);
    }

    /* destroy the ssl params */
    tibemsSSLParams_Destroy(sslParams);

    RETURN_TRUE;
}

PHP_FUNCTION(tibco_sendmsg)
{
    char*           name         = NULL;
    int             name_len     = 0;
    char*           data         = NULL;
    int             data_len     = 0;    
    tibems_bool     useTopic     = TIBEMS_TRUE;
    zend_bool       usetTopic    = 1;

    tibemsTextMsg msg    = NULL;
    int           i;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|b", &name, &name_len, &data, &data_len, &usetTopic) == FAILURE) {
        RETURN_NULL();
    }

    if(usetTopic == 0) useTopic = TIBEMS_FALSE;

    if (!name) 
    {
	php_error_docref(NULL TSRMLS_CC, E_WARNING, "must specify destination name");
    }
    
    if (strlen(data) == 0) 
    {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "must specify at least one message text");
    }
    
    if (status != TIBEMS_OK)
    {
        fail("No Tibco connection established", status);
    }

    /* create the destination */
    if (useTopic)
        status = tibemsTopic_Create(&destination,name);
    else
        status = tibemsQueue_Create(&destination,name);
    if (status != TIBEMS_OK)
    {
        fail("Error creating tibemsDestination", status);
    }

    /* create the session */
    status = tibemsConnection_CreateSession(connection,
            &session,TIBEMS_FALSE,TIBEMS_AUTO_ACKNOWLEDGE);
    if (status != TIBEMS_OK)
    {
        fail("Error creating tibemsSession", status);
    }


    /* create the producer */
    status = tibemsSession_CreateProducer(session,
            &msgProducer,destination);
    if (status != TIBEMS_OK)
    {
        fail("Error creating tibemsMsgProducer", status);
    }

    /* create the text message */
    status = tibemsTextMsg_Create(&msg);
    if (status != TIBEMS_OK)
    {
        fail("Error creating tibemsTextMsg", status);
    }
        
    /* set the message text */
    status = tibemsTextMsg_SetText(msg,data);
    if (status != TIBEMS_OK)
    {
        fail("Error setting tibemsTextMsg text", status);
    }

    /* publish the message */
    status = tibemsMsgProducer_Send(msgProducer,msg);
    if (status != TIBEMS_OK)
    {
        fail("Error publishing tibemsTextMsg", status);
    }
        
    /* destroy the message */
    status = tibemsMsg_Destroy(msg);
    if (status != TIBEMS_OK)
    {
        fail("Error destroying tibemsTextMsg", status);
    }
    
    /* destroy the destination */
    status = tibemsDestination_Destroy(destination);
    if (status != TIBEMS_OK)
    {
        fail("Error destroying tibemsDestination", status);
    }

    RETURN_TRUE;
}

PHP_FUNCTION(tibco_recvmsg)
{
    char*           name         = NULL;
    int             name_len     = 0;
    tibemsTextMsg msg         = NULL;
    const char*   txt         = NULL;
    char*         textmessage = NULL;
    int           receive     = 1;
    tibemsMsgType msgType     = TIBEMS_MESSAGE_UNKNOWN;
    char*         msgTypeName = "UNKNOWN";
    tibems_long     rtimeout = 10;
    tibems_bool     useTopic     = TIBEMS_TRUE;
    zend_bool       usetTopic    = 1;
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|bl", &name, &name_len, &usetTopic, &rtimeout) == FAILURE) {
        RETURN_NULL();
    }

    int           i;

    if(usetTopic == 0) useTopic = TIBEMS_FALSE;

    if (!name) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "must specify destination name\n");
    }
    
    /* set the exception listener */
    status = tibemsConnection_SetExceptionListener(connection,
            onException, NULL);
    if (status != TIBEMS_OK)
    {
        fail("Error setting exception listener", status);
    }

    /* create the destination */
    if (useTopic)
        status = tibemsTopic_Create(&destination,name);
    else
        status = tibemsQueue_Create(&destination,name);
    if (status != TIBEMS_OK)
    {
        fail("Error creating tibemsDestination", status);
    }
        
    /* create the session */
    status = tibemsConnection_CreateSession(connection,
            &session,TIBEMS_FALSE,TIBEMS_AUTO_ACKNOWLEDGE);
    if (status != TIBEMS_OK)
    {
        fail("Error creating tibemsSession", status);
    }
        
    /* create the consumer */
    status = tibemsSession_CreateConsumer(session,
            &msgConsumer,destination,NULL,TIBEMS_FALSE);
    if (status != TIBEMS_OK)
    {
        fail("Error creating tibemsMsgConsumer", status);
    }
    
    /* start the connection */
    status = tibemsConnection_Start(connection);
    if (status != TIBEMS_OK)
    {
        fail("Error starting tibemsConnection", status);
    }

    /* receive the message */
    status = tibemsMsgConsumer_ReceiveTimeout(msgConsumer,&msg,rtimeout);
    if (status != TIBEMS_OK)
    {
        if ((status == TIBEMS_NOT_FOUND) || (status == TIBEMS_TIMEOUT))
        {
            RETURN_FALSE;
        }
        fail("Error receiving message", status);
    }

    /* check message type */
    status = tibemsMsg_GetBodyType(msg,&msgType);
    if (status != TIBEMS_OK)
    {
        fail("Error getting message type", status);
    }

    switch(msgType)
    {
        case TIBEMS_MESSAGE:
            msgTypeName = "MESSAGE";
            break;

        case TIBEMS_BYTES_MESSAGE:
            msgTypeName = "BYTES";
            break;

        case TIBEMS_OBJECT_MESSAGE:
            msgTypeName = "OBJECT";
            break;

        case TIBEMS_STREAM_MESSAGE:
            msgTypeName = "STREAM";
            break;

        case TIBEMS_MAP_MESSAGE:
            msgTypeName = "MAP";
            break;

        case TIBEMS_TEXT_MESSAGE:
            msgTypeName = "TEXT";
            break;

        default:
            msgTypeName = "UNKNOWN";
            break;
    }

    /* publish sample sends TEXT message, if received other
     * just print entire message
     */
    if (msgType != TIBEMS_TEXT_MESSAGE)
    {
        php_printf("Received %s message:\n",msgTypeName);
        tibemsMsg_Print(msg);
    }
    else
    {
        /* get the message text */
        status = tibemsTextMsg_GetText(msg,&txt);
        if (status != TIBEMS_OK)
        {
            fail("Error getting tibemsTextMsg text", status);
        }
	textmessage = malloc(sizeof(char)*strlen(txt));
	strcpy(textmessage, txt);
    }

    /* destroy the message */
    status = tibemsMsg_Destroy(msg);
    if (status != TIBEMS_OK)
    {
        fail("Error destroying tibemsMsg", status);
    }

    /* destroy the destination */
    status = tibemsDestination_Destroy(destination);
    if (status != TIBEMS_OK)
    {
        fail("Error destroying tibemsDestination", status);
    }

    RETURN_STRING(textmessage ? textmessage : "<text is set to NULL>",1);
}

PHP_FUNCTION(tibco_connect)
{

    char*           serverUrl     = NULL;
    int             serverUrl_len = 0;
    char*           userName      = NULL;
    int             userName_len  = 0;
    char*           password      = NULL;
    int             password_len  = 0;
    char*           pk_password   = NULL;
    int             pk_password_len = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss|s", &serverUrl, &serverUrl_len, &userName, &userName_len, &password, &password_len, &pk_password, &pk_password_len) == FAILURE) {
        RETURN_NULL();
    }

    /* create the connection, use ssl if specified */
    if(sslParams)
    {
        status = tibemsConnection_CreateSSL(&connection,
                serverUrl,NULL,userName,password,sslParams,pk_password);
    }
    else
    {
        status = tibemsConnection_Create(&connection,
                serverUrl,NULL,userName,password);
    }

    if (status != TIBEMS_OK)
    {
        fail("Error creating tibemsConnection", status);
    }

    RETURN_TRUE;
}
