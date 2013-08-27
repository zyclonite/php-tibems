/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: status.h,v $
 * $Revision: 1.33 $
 * $Date: 2004/09/01 22:40:14 $
 */

#ifndef _INCLUDED_tibemsstatus_h
#define _INCLUDED_tibemsstatus_h

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum
{
    TIBEMS_OK                    = 0,

    TIBEMS_ILLEGAL_STATE         = 1,
    TIBEMS_INVALID_CLIENT_ID     = 2,
    TIBEMS_INVALID_DESTINATION   = 3,
    TIBEMS_INVALID_SELECTOR      = 4,

    TIBEMS_EXCEPTION             = 5,
    TIBEMS_SECURITY_EXCEPTION    = 6,

    TIBEMS_MSG_EOF               = 7,

    TIBEMS_MSG_NOT_READABLE      = 9,
    TIBEMS_MSG_NOT_WRITEABLE     = 10,

    TIBEMS_SERVER_NOT_CONNECTED  = 11,
    TIBEMS_VERSION_MISMATCH      = 12,
    TIBEMS_SUBJECT_COLLISION     = 13,

    TIBEMS_INVALID_PROTOCOL      = 15,
    TIBEMS_INVALID_HOSTNAME      = 17,
    TIBEMS_INVALID_PORT          = 18,
    TIBEMS_NO_MEMORY             = 19,
    TIBEMS_INVALID_ARG           = 20,

    TIBEMS_SERVER_LIMIT          = 21,

    TIBEMS_MSG_DUPLICATE         = 22,

    TIBEMS_NOT_PERMITTED         = 27,

    TIBEMS_SERVER_RECONNECTED    = 28,

    TIBEMS_INVALID_NAME          = 30,
    TIBEMS_INVALID_TYPE          = 31,
    TIBEMS_INVALID_SIZE          = 32,
    TIBEMS_INVALID_COUNT         = 33,
    TIBEMS_NOT_FOUND             = 35,
    TIBEMS_ID_IN_USE             = 36,
    TIBEMS_ID_CONFLICT           = 37,
    TIBEMS_CONVERSION_FAILED     = 38,

    TIBEMS_INVALID_MSG           = 42,
    TIBEMS_INVALID_FIELD         = 43,
    TIBEMS_INVALID_INSTANCE      = 44,
    TIBEMS_CORRUPT_MSG           = 45,

    TIBEMS_PRODUCER_FAILED       = 47,

    TIBEMS_TIMEOUT               = 50,
    TIBEMS_INTR                  = 51,
    TIBEMS_QUEUE_LIMIT_EXCEEDED  = 52,
    TIBEMS_MEM_LIMIT_EXCEEDED    = 53,
    TIBEMS_USER_INTR             = 54,

    TIBEMS_INVALID_TIME_INTERVAL = 64,
    TIBEMS_INVALID_IO_SOURCE     = 65,

    TIBEMS_OS_ERROR              = 68,

    TIBEMS_INSUFFICIENT_BUFFER   = 70,

    TIBEMS_EOF                   = 71,
    TIBEMS_INVALID_FILE          = 72,
    TIBEMS_FILE_NOT_FOUND        = 73,
    TIBEMS_IO_FAILED             = 74,

    TIBEMS_NOT_FILE_OWNER        = 80,

    TIBEMS_ALREADY_EXISTS        = 91,

    TIBEMS_INVALID_CONNECTION    = 100,
    TIBEMS_INVALID_SESSION       = 101,
    TIBEMS_INVALID_CONSUMER      = 102,
    TIBEMS_INVALID_PRODUCER      = 103,
    TIBEMS_INVALID_USER          = 104,
    TIBEMS_INVALID_GROUP         = 105,

    TIBEMS_TRANSACTION_FAILED    = 106,
    TIBEMS_TRANSACTION_ROLLBACK  = 107,
    TIBEMS_TRANSACTION_RETRY     = 108,

    TIBEMS_INVALID_XARESOURCE    = 109,

    TIBEMS_FT_SERVER_LACKS_TRANSACTION = 110,

    TIBEMS_LDAP_ERROR            = 120,

    /* SSL related errors */
    TIBEMS_INVALID_CERT          = 150,
    TIBEMS_INVALID_CERT_NOT_YET  = 151,   
    TIBEMS_INVALID_CERT_EXPIRED  = 152,
    TIBEMS_INVALID_CERT_DATA     = 153,
    TIBEMS_ALGORITHM_ERROR       = 154,
    TIBEMS_SSL_ERROR             = 155,   
    TIBEMS_INVALID_PRIVATE_KEY   = 156,
    TIBEMS_INVALID_ENCODING      = 157,
    TIBEMS_NOT_ENOUGH_RANDOM     = 158,
    TIBEMS_INVALID_CRL_DATA      = 159,
    TIBEMS_CRL_OFF               = 160,

    TIBEMS_NOT_IMPLEMENTED       = 255

} tibems_status;

extern const char*
tibemsStatus_GetText(
    tibems_status        status);


#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsstatus_h */
