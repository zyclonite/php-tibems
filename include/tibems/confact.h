/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: confact.h,v $
 * $Revision: 1.19 $
 * $Date: 2005/12/09 23:39:02 $
 */

#ifndef _INCLUDED_tibemsconnfactory_h
#define _INCLUDED_tibemsconnfactory_h

#include "types.h"
#include "status.h"
#include "cssl.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* All the connection factory object are the same with a type identifier */
typedef struct __tibemsConnectionFactory*       tibemsConnectionFactory;
typedef struct __tibemsConnectionFactory*       tibemsTopicConnectionFactory;
typedef struct __tibemsConnectionFactory*       tibemsQueueConnectionFactory;
typedef struct __tibemsConnectionFactory*       tibemsXAConnectionFactory;
typedef struct __tibemsConnectionFactory*       tibemsXATopicConnectionFactory;
typedef struct __tibemsConnectionFactory*       tibemsXAQueueConnectionFactory;


/*
 * connection factory types returned by tibemsConnectionFactory_GetType
 */
typedef enum  __tibemsConnectionFactoryType
{
    TIBEMS_CONNECTION_FACTORY           = 0,   /* should match TIBEMS_UNKNOWN etc*/
    TIBEMS_QUEUE_CONNECTION_FACTORY     = 1,
    TIBEMS_TOPIC_CONNECTION_FACTORY     = 2,
    TIBEMS_XA_CONNECTION_FACTORY        = 3,
    TIBEMS_XA_QUEUE_CONNECTION_FACTORY  = 4,
    TIBEMS_XA_TOPIC_CONNECTION_FACTORY  = 5

} tibemsConnectionFactoryType;

/* connection factory load balance metric types */
typedef enum __tibemsFactoryLoadBalanceMetric
{

    TIBEMS_FACTORY_LOAD_BALANCE_METRIC_NONE             = 0,
    TIBEMS_FACTORY_LOAD_BALANCE_METRIC_CONNECTIONS      = 1,
    TIBEMS_FACTORY_LOAD_BALANCE_METRIC_BYTE_RATE        = 2
    
} tibemsFactoryLoadBalanceMetric;

/* destroy the connection factory */
extern tibems_status
tibemsConnectionFactory_Destroy(
    tibemsConnectionFactory             factory);

extern tibems_status
tibemsConnectionFactory_GetType(
    tibemsConnectionFactory             factory,
    tibemsConnectionFactoryType*        type);

extern tibems_status
tibemsConnectionFactory_CreateConnection(
    tibemsConnectionFactory             factory,
    tibemsConnection*                   connection,
    const char *                        username,
    const char *                        password);


extern tibems_status
tibemsTopicConnectionFactory_CreateConnection(
    tibemsTopicConnectionFactory        factory,
    tibemsTopicConnection*              connection,
    const char *                        username,
    const char *                        password);


extern tibems_status
tibemsQueueConnectionFactory_CreateConnection(
    tibemsQueueConnectionFactory        factory,
    tibemsQueueConnection*              connection,
    const char *                        username,
    const char *                        password);


extern tibems_status
tibemsXAConnectionFactory_CreateXAConnection(
    tibemsXAConnectionFactory           factory,
    tibemsConnection*                   connection,
    const char *                        username,
    const char *                        password);


extern tibems_status
tibemsXATopicConnectionFactory_CreateXAConnection(
    tibemsXATopicConnectionFactory      factory,
    tibemsTopicConnection*              connection,
    const char *                        username,
    const char *                        password);


extern tibems_status
tibemsXAQueueConnectionFactory_CreateXAConnection(
    tibemsXAQueueConnectionFactory      factory,
    tibemsQueueConnection*              connection,
    const char *                        username,
    const char *                        password);

extern tibems_status
tibemsConnectionFactory_CreateConnectionSSL(
    tibemsConnectionFactory             factory,
    tibemsConnection*                   connection,
    const char *                        username,
    const char *                        password,
    tibemsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibems_status
tibemsTopicConnectionFactory_CreateConnectionSSL(
    tibemsTopicConnectionFactory        factory,
    tibemsTopicConnection*              connection,
    const char *                        username,
    const char *                        password,
    tibemsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibems_status
tibemsQueueConnectionFactory_CreateConnectionSSL(
    tibemsQueueConnectionFactory        factory,
    tibemsQueueConnection*              connection,
    const char *                        username,
    const char *                        password,
    tibemsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibems_status
tibemsXAConnectionFactory_CreateXAConnectionSSL(
    tibemsXAConnectionFactory           factory,
    tibemsConnection*                   connection,
    const char *                        username,
    const char *                        password,
    tibemsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibems_status
tibemsXATopicConnectionFactory_CreateXAConnectionSSL(
    tibemsXATopicConnectionFactory      factory,
    tibemsTopicConnection*              connection,
    const char *                        username,
    const char *                        password,
    tibemsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibems_status
tibemsXAQueueConnectionFactory_CreateXAConnectionSSL(
    tibemsXAQueueConnectionFactory      factory,
    tibemsQueueConnection*              connection,
    const char *                        username,
    const char *                        password,
    tibemsSSLParams                     SSLparams,
    const char *                        pk_password);

extern tibemsConnectionFactory
tibemsConnectionFactory_Create(void);

extern tibems_status
tibemsConnectionFactory_SetType(
    tibemsConnectionFactory             factory,
    tibemsConnectionFactoryType         type);

extern tibems_status
tibemsConnectionFactory_SetServerURL(
    tibemsConnectionFactory             factory,
    const char*                         url);

extern tibems_status
tibemsConnectionFactory_SetClientID(
    tibemsConnectionFactory             factory,
    const char*                         cid);

extern tibems_status
tibemsConnectionFactory_SetMetric(
    tibemsConnectionFactory             factory,
    tibemsFactoryLoadBalanceMetric      metric);

extern tibems_status
tibemsConnectionFactory_SetConnectAttemptCount(
    tibemsConnectionFactory             factory,
    tibems_int                          connAttempts);

extern tibems_status
tibemsConnectionFactory_SetConnectAttemptDelay(
    tibemsConnectionFactory             factory,
    tibems_int                          delay);

extern tibems_status
tibemsConnectionFactory_SetReconnectAttemptCount(
    tibemsConnectionFactory             factory,
    tibems_int                          connAttempts);

extern tibems_status
tibemsConnectionFactory_SetReconnectAttemptDelay(
    tibemsConnectionFactory             factory,
    tibems_int                          delay);

/*
 * sslparams will be destroyed when factory is
 * destroyed in tibemsConnectionFactory_Destroy()
 */
extern tibems_status
tibemsConnectionFactory_SetSSLParams(
    tibemsConnectionFactory             factory,
    tibemsSSLParams                     sslparams);


#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsconnfactory_h */
