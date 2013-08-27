/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: tibjms.h,v $
 * $Revision: 1.17 $
 * $Date: 2006/01/25 17:56:37 $
 */

#ifndef _INCLUDED_tibjms_h
#define _INCLUDED_tibjms_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#if defined(__cplusplus)
extern "C" {
#endif

#define TIBJMS_DEFAULT_BROKER                   "tcp://localhost:7222"
#define TIBJMS_DEFAULT_HOST                     "localhost"
#define TIBJMS_DEFAULT_PORT                     "7222"
#define TIBJMS_DEFAULT_SSL_PORT                 "7243"

#define TIBJMS_DEFAULT_USER                     "anonymous"

#define TIBJMS_GROUP_ALL                        "$all"
#define TIBJMS_GROUP_ADMIN                      "$admin"
#define TIBJMS_USER_ADMIN                       "admin"

#define TIBJMS_UNDELIVERED_QUEUE                "$sys.undelivered"

#define TIBJMS_DEFAULT_DELIVERY_MODE            (TIBJMS_PERSISTENT)
#define TIBJMS_DEFAULT_PRIORITY                 ((tibjms_int)4)
#define TIBJMS_DEFAULT_TIME_TO_LIVE             ((tibjms_long)0)

#define JMS_TIBCO_COMPRESS                      "JMS_TIBCO_COMPRESS"

#define JMS_TIBCO_IMPORTED                      "JMS_TIBCO_IMPORTED"
#define JMS_TIBCO_MSG_EXT                       "JMS_TIBCO_MSG_EXT"

#define JMS_TIBCO_CM_PUBLISHER                  "JMS_TIBCO_CM_PUBLISHER"
#define JMS_TIBCO_CM_SEQUENCE                   "JMS_TIBCO_CM_SEQUENCE"

#define JMS_TIBCO_SS_SENDER                     "JMS_TIBCO_SS_SENDER"
#define JMS_TIBCO_SS_DELIVERY_MODE              "JMS_TIBCO_SS_DELIVERY_MODE"
#define JMS_TIBCO_SS_EXPIRATION                 "JMS_TIBCO_SS_EXPIRATION"
#define JMS_TIBCO_SS_LB_MODE                    "JMS_TIBCO_SS_LB_MODE"
#define JMS_TIBCO_SS_MESSAGE_ID                 "JMS_TIBCO_SS_MESSAGE_ID"
#define JMS_TIBCO_SS_PRIORITY                   "JMS_TIBCO_SS_PRIORITY"
#define JMS_TIBCO_SS_SENDER_TIMESTAMP           "JMS_TIBCO_SS_SENDER_TIMESTAMP"
#define JMS_TIBCO_SS_TYPE_NUM                   "JMS_TIBCO_SS_TYPE_NUM"
#define JMS_TIBCO_SS_CORRELATION_ID             "JMS_TIBCO_SS_CORRELATION_ID"
#define JMS_TIBCO_SS_SEQ_NUM                    "JMS_TIBCO_SS_SEQ_NUM"
#define JMS_TIBCO_SS_USER_PROP                  "JMS_TIBCO_SS_USER_PROP"

#define JMS_TIBCO_SENDER                        "JMS_TIBCO_SENDER"
#define JMS_TIBCO_DISABLE_SENDER                "JMS_TIBCO_DISABLE_SENDER"

#define JMS_TIBCO_PRESERVE_UNDELIVERED          "JMS_TIBCO_PRESERVE_UNDELIVERED"

#define JMS_TIBCO_MSG_TRACE                     "JMS_TIBCO_MSG_TRACE"

#define TIBJMS_USER_NAME_MAX                    (127)
#define TIBJMS_GROUP_NAME_MAX                   (127)
#define TIBJMS_DESTINATION_MAX                  (255)
#define TIBJMS_JNDI_NAME_MAX                    (255)
#define TIBJMS_DURABLE_MAX                      (255)
#define TIBJMS_TPORT_NAME_MAX                   (64)

/*
 * Basic JMS types for header properties.
 */

/*
 * 64 bit integer support.
 *
 * If the type your compiler uses for a 64 bit integer
 * is not covered below, define TIBJMS_I64 to be
 * the type your compiler uses for 64 bit integers.
 */

#if !defined(TIBX_I64)
# if defined(_WIN32) || defined(__vms)
#  define TIBX_I64 __int64
# elif defined(__alpha)
#  define TIBX_I64 long
# else
#  define TIBX_I64 long long
# endif
#endif


typedef char                                    tibjms_byte;
typedef short                                   tibjms_short;
typedef unsigned short                          tibjms_wchar;
typedef int                                     tibjms_int;
typedef TIBX_I64                                tibjms_long;

typedef float                                   tibjms_float;
typedef double                                  tibjms_double;

typedef unsigned int                            tibjms_uint;

typedef enum
{
    TIBJMS_FALSE  = 0,
    TIBJMS_TRUE   = 1
} tibjms_bool;


typedef enum
{
    TIBJMS_UNKNOWN                              = 0,
    TIBJMS_QUEUE                                = 1,
    TIBJMS_TOPIC                                = 2,
    TIBJMS_DEST_UNDEFINED                       = 256

} tibjmsDestinationType;


typedef enum
{
    TIBJMS_AUTO_ACKNOWLEDGE                     = 1,
    TIBJMS_CLIENT_ACKNOWLEDGE                   = 2,
    TIBJMS_DUPS_OK_ACKNOWLEDGE                  = 3,

    TIBJMS_NO_ACKNOWLEDGE                       = 22,   /* Extensions */
    TIBJMS_EXPLICIT_CLIENT_ACKNOWLEDGE          = 23,
    TIBJMS_EXPLICIT_CLIENT_DUPS_OK_ACKNOWLEDGE  = 24

} tibjmsAcknowledgeMode;


typedef enum
{
    TIBJMS_NON_PERSISTENT                       = 1,
    TIBJMS_PERSISTENT                           = 2,
    TIBJMS_RELIABLE                             = 22    /* Extension */

} tibjmsDeliveryMode;


/* message type */

typedef enum
{
    TIBJMS_MESSAGE_UNKNOWN                      = 0,
    TIBJMS_MESSAGE                              = 1,
    TIBJMS_BYTES_MESSAGE                        = 2,
    TIBJMS_MAP_MESSAGE                          = 3,
    TIBJMS_OBJECT_MESSAGE                       = 4,
    TIBJMS_STREAM_MESSAGE                       = 5,
    TIBJMS_TEXT_MESSAGE                         = 6,
    TIBJMS_MESSAGE_UNDEFINED                    = 256

} tibjmsMsgType;


typedef union
{
    tibjms_bool                                 boolValue;
    tibjms_byte                                 byteValue;
    tibjms_short                                shortValue;
    tibjms_wchar                                wcharValue;
    tibjms_int                                  intValue;
    tibjms_long                                 longValue;
    tibjms_float                                floatValue;
    tibjms_double                               doubleValue;
    char*                                       utf8Value;
    void*                                       bytesValue;
    struct __tibjmsMsg*                         msgValue;
    void*                                       arrayValue;

} tibjmsData;

#define TIBJMS_NULL                             0
#define TIBJMS_BOOL                             1
#define TIBJMS_BYTE                             2
#define TIBJMS_WCHAR                            3  /* double byte */
#define TIBJMS_SHORT                            4
#define TIBJMS_INT                              5
#define TIBJMS_LONG                             6
#define TIBJMS_FLOAT                            7
#define TIBJMS_DOUBLE                           8
/* Explicit size items */
#define TIBJMS_UTF8                             9   /* UTF8-encoded String */
#define TIBJMS_BYTES                            10
/* Extended MapMsg types */
#define TIBJMS_MAP_MSG                          11
#define TIBJMS_STREAM_MSG                       12
#define TIBJMS_SHORT_ARRAY                      20
#define TIBJMS_INT_ARRAY                        21
#define TIBJMS_LONG_ARRAY                       22
#define TIBJMS_FLOAT_ARRAY                      23
#define TIBJMS_DOUBLE_ARRAY                     24

typedef struct
{
    tibjms_byte                 type;   /* one of TIBJMS_BOOL etc. */
    tibjms_int                  size;   /* data size in bytes, 0 if can't tell */
    tibjms_int                  count;  /* only for arrays: element count */
    tibjmsData                  data;

} tibjmsMsgField;

/*
 * JMS Objects Mappings
 */

typedef struct __tibjmsMsg*                     tibjmsMsg;

typedef struct __tibjmsMsg*                     tibjmsBytesMsg;
typedef struct __tibjmsMsg*                     tibjmsMapMsg;
typedef struct __tibjmsMsg*                     tibjmsObjectMsg;
typedef struct __tibjmsMsg*                     tibjmsStreamMsg;
typedef struct __tibjmsMsg*                     tibjmsTextMsg;

typedef struct __tibjmsMsgEnum*                 tibjmsMsgEnum;

typedef struct __tibjmsConnection*              tibjmsConnection;
typedef struct __tibjmsConnection*              tibjmsTopicConnection;
typedef struct __tibjmsConnection*              tibjmsQueueConnection;

typedef struct __tibjmsSession*                 tibjmsSession;
typedef struct __tibjmsSession*                 tibjmsTopicSession;
typedef struct __tibjmsSession*                 tibjmsQueueSession;

typedef struct __tibjmsDestination*             tibjmsDestination;
typedef struct __tibjmsDestination*             tibjmsTopic;
typedef struct __tibjmsDestination*             tibjmsTemporaryTopic;

typedef struct __tibjmsDestination*             tibjmsQueue;
typedef struct __tibjmsDestination*             tibjmsTemporaryQueue;

typedef struct __tibjmsMsgProducer*             tibjmsMsgProducer;
typedef struct __tibjmsMsgConsumer*             tibjmsMsgConsumer;
typedef struct __tibjmsMsgRequestor*            tibjmsMsgRequestor;

typedef struct __tibjmsMsgConsumer*             tibjmsTopicSubscriber;
typedef struct __tibjmsMsgProducer*             tibjmsTopicPublisher;
typedef struct __tibjmsMsgRequestor*            tibjmsTopicRequestor;

typedef struct __tibjmsQueueBrowser*            tibjmsQueueBrowser;

typedef struct __tibjmsMsgConsumer*             tibjmsQueueReceiver;
typedef struct __tibjmsMsgProducer*             tibjmsQueueSender;
typedef struct __tibjmsMsgRequestor*            tibjmsQueueRequestor;

typedef struct __tibjmsExceptionListener*       tibjmsExceptionListener;
typedef struct __tibjmsConnectionMetaData*      tibjmsConnectionMetaData;

typedef struct __tibjmsSSLParams*               tibjmsSSLParams;

typedef struct __tibjmsXAResource*              tibjmsXAResource;


typedef enum
{
    TIBJMS_OK                    = 0,

    TIBJMS_ILLEGAL_STATE         = 1,
    TIBJMS_INVALID_CLIENT_ID     = 2,
    TIBJMS_INVALID_DESTINATION   = 3,
    TIBJMS_INVALID_SELECTOR      = 4,

    TIBJMS_EXCEPTION             = 5,
    TIBJMS_SECURITY_EXCEPTION    = 6,

    TIBJMS_MSG_EOF               = 7,

    TIBJMS_MSG_NOT_READABLE      = 9,
    TIBJMS_MSG_NOT_WRITEABLE     = 10,

    TIBJMS_SERVER_NOT_CONNECTED  = 11,
    TIBJMS_VERSION_MISMATCH      = 12,
    TIBJMS_SUBJECT_COLLISION     = 13,

    TIBJMS_INVALID_PROTOCOL      = 15,
    TIBJMS_INVALID_HOSTNAME      = 17,
    TIBJMS_INVALID_PORT          = 18,
    TIBJMS_NO_MEMORY             = 19,
    TIBJMS_INVALID_ARG           = 20,

    TIBJMS_SERVER_LIMIT          = 21,

    TIBJMS_MSG_DUPLICATE         = 22,

    TIBJMS_NOT_PERMITTED         = 27,

    TIBJMS_SERVER_RECONNECTED    = 28,

    TIBJMS_INVALID_NAME          = 30,
    TIBJMS_INVALID_TYPE          = 31,
    TIBJMS_INVALID_SIZE          = 32,
    TIBJMS_INVALID_COUNT         = 33,
    TIBJMS_NOT_FOUND             = 35,
    TIBJMS_ID_IN_USE             = 36,
    TIBJMS_ID_CONFLICT           = 37,
    TIBJMS_CONVERSION_FAILED     = 38,

    TIBJMS_INVALID_MSG           = 42,
    TIBJMS_INVALID_FIELD         = 43,
    TIBJMS_INVALID_INSTANCE      = 44,
    TIBJMS_CORRUPT_MSG           = 45,

    TIBJMS_TIMEOUT               = 50,
    TIBJMS_INTR                  = 51,
    TIBJMS_QUEUE_LIMIT_EXCEEDED  = 52,
    TIBJMS_MEM_LIMIT_EXCEEDED    = 53,

    TIBJMS_INVALID_TIME_INTERVAL = 64,
    TIBJMS_INVALID_IO_SOURCE     = 65,

    TIBJMS_OS_ERROR              = 68,

    TIBJMS_INSUFFICIENT_BUFFER   = 70,

    TIBJMS_EOF                   = 71,
    TIBJMS_INVALID_FILE          = 72,
    TIBJMS_FILE_NOT_FOUND        = 73,
    TIBJMS_IO_FAILED             = 74,

    TIBJMS_NOT_FILE_OWNER        = 80,

    TIBJMS_ALREADY_EXISTS        = 91,

    TIBJMS_INVALID_CONNECTION    = 100,
    TIBJMS_INVALID_SESSION       = 101,
    TIBJMS_INVALID_CONSUMER      = 102,
    TIBJMS_INVALID_PRODUCER      = 103,
    TIBJMS_INVALID_USER          = 104,
    TIBJMS_INVALID_GROUP         = 105,

    TIBJMS_TRANSACTION_FAILED    = 106,
    TIBJMS_TRANSACTION_ROLLBACK  = 107,
    TIBJMS_TRANSACTION_RETRY     = 108,

    TIBJMS_INVALID_XARESOURCE    = 109,

    TIBJMS_LDAP_ERROR            = 120,

    /* SSL related errors */
    TIBJMS_INVALID_CERT          = 150,
    TIBJMS_INVALID_CERT_NOT_YET  = 151,   
    TIBJMS_INVALID_CERT_EXPIRED  = 152,
    TIBJMS_INVALID_CERT_DATA     = 153,
    TIBJMS_ALGORITHM_ERROR       = 154,
    TIBJMS_SSL_ERROR             = 155,   
    TIBJMS_INVALID_PRIVATE_KEY   = 156,
    TIBJMS_INVALID_ENCODING      = 157,
    TIBJMS_NOT_ENOUGH_RANDOM     = 158,
    TIBJMS_INVALID_CRL_DATA      = 159,
    TIBJMS_CRL_OFF               = 160,

    TIBJMS_NOT_IMPLEMENTED       = 255

} tibjms_status;

extern const char*
tibjmsStatus_GetText(
    tibjms_status        status);


extern tibjms_status
tibjmsDestination_Create(
    tibjmsDestination*          destination,
    tibjmsDestinationType       type,
    const char*                 name);

extern tibjms_status
tibjmsDestination_Destroy(
    tibjmsDestination           destination);

extern tibjms_status
tibjmsDestination_Copy(
    tibjmsDestination           destination,
    tibjmsDestination*          copy);

extern tibjms_status
tibjmsDestination_GetName(
    tibjmsDestination           destination,
    char*                       name,
    tibjms_int                  name_len);

extern tibjms_status
tibjmsDestination_GetType(
    tibjmsDestination           destination,
    tibjmsDestinationType*      type);

/* queues */
extern tibjms_status
tibjmsQueue_Create(
    tibjmsQueue*                queue,
    const char*                 queueName);

extern tibjms_status
tibjmsQueue_GetQueueName(
    tibjmsQueue                 queue,
    char*                       name,
    tibjms_int                  name_len);

extern tibjms_status
tibjmsQueue_Destroy(
    tibjmsQueue                 queue);

/* topics */
extern tibjms_status
tibjmsTopic_Create(
    tibjmsTopic*                topic,
    const char*                 topicName);

extern tibjms_status
tibjmsTopic_Destroy(
    tibjmsTopic                 topic);

extern tibjms_status
tibjmsTopic_GetTopicName(
    tibjmsTopic                 topic,
    char*                       name,
    tibjms_int                  name_len);


typedef void
(*tibjmsExceptionCallback) (
    tibjmsConnection    connection,
    tibjms_status       status,
    void*               closure);

extern tibjms_status
tibjmsConnection_Create(
    tibjmsConnection*           connection,
    const char*                 brokerURL,
    const char*                 clientId,
    const char*                 username,
    const char*                 password);

extern tibjms_status
tibjmsConnection_CreateSession(
    tibjmsConnection            connection,
    tibjmsSession*              session,
    tibjms_bool                 transacted,
    tibjmsAcknowledgeMode       acknowledgeMode);

extern tibjms_status
tibjmsConnection_Close(
    tibjmsConnection            connection);

extern tibjms_status
tibjmsConnection_Start(
    tibjmsConnection            connection);

extern tibjms_status
tibjmsConnection_Stop(
    tibjmsConnection            connection);

extern tibjms_status
tibjmsConnection_GetClientId(
    tibjmsConnection            connection,
    const char**                clientId);

extern tibjms_status
tibjmsConnection_SetClientId(
    tibjmsConnection            connection,
    const char*                 clientId);

extern tibjms_status
tibjmsConnection_GetExceptionListener(
    tibjmsConnection            connection,
    tibjmsExceptionCallback*    listener,
    void**                      closure);

extern tibjms_status
tibjmsConnection_SetExceptionListener(
    tibjmsConnection            connection,
    tibjmsExceptionCallback     listenerCallback,
    const void*                 closure);

extern tibjms_status
tibjmsConnection_GetMetaData(
    tibjmsConnection            connection,
    tibjmsConnectionMetaData*   metaData);

extern tibjms_status
tibjmsConnection_GetActiveURL(
    tibjmsConnection            connection,
    char**                      serverURL);


extern void
tibjms_Sleep(tibjms_long milliseconds);


/* Multithreaded access OK for close */
extern tibjms_status
tibjmsSession_Close(
    tibjmsSession               session);

extern tibjms_status
tibjmsSession_Commit(
    tibjmsSession               session);

extern tibjms_status
tibjmsSession_CreateConsumer(
    tibjmsSession               session,
    tibjmsMsgConsumer*          consumer,
    tibjmsDestination           destination,
    const char*                 optionalSelector,
    tibjms_bool                 noLocal);

extern tibjms_status
tibjmsSession_CreateDurableSubscriber(
    tibjmsSession               session,
    tibjmsTopicSubscriber*      topicSubscriber,
    tibjmsTopic                 topic,
    const char*                 subscriberName,
    const char*                 optionalSelector,
    tibjms_bool                 noLocal);

extern tibjms_status
tibjmsSession_CreateBrowser(
    tibjmsSession               session,
    tibjmsQueueBrowser*         browser,
    tibjmsQueue                 queue,
    const char*                 optionalSelector);

extern tibjms_status
tibjmsSession_CreateProducer(
    tibjmsSession               session,
    tibjmsMsgProducer*          producer,
    tibjmsDestination           destination);

extern tibjms_status
tibjmsSession_CreateBytesMessage(
    tibjmsSession               session,
    tibjmsBytesMsg*             bytesMsg);

extern tibjms_status
tibjmsSession_CreateMapMessage(
    tibjmsSession               session,
    tibjmsMapMsg*               mapMsg);

extern tibjms_status
tibjmsSession_CreateMessage(
    tibjmsSession               session,
    tibjmsMsg*                  msg);

extern tibjms_status
tibjmsSession_CreateStreamMessage(
    tibjmsSession               session,
    tibjmsStreamMsg*            streamMsg);

extern tibjms_status
tibjmsSession_CreateTextMessage(
    tibjmsSession               session,
    tibjmsTextMsg*              textMsg);

extern tibjms_status
tibjmsSession_CreateTextMessageEx(
    tibjmsSession               session,
    tibjmsTextMsg*              textMsg,
    const char*                 textString);

extern tibjms_status
tibjmsSession_GetTransacted(
    tibjmsSession               session,
    tibjms_bool*                isTransacted);

extern tibjms_status
tibjmsSession_GetAcknowledgeMode(
    tibjmsSession               session,
    tibjmsAcknowledgeMode*      acknowledgeMode);

extern tibjms_status
tibjmsSession_Recover(
    tibjmsSession               session);

extern tibjms_status
tibjmsSession_Rollback(
    tibjmsSession               session);

extern tibjms_status
tibjmsSession_Unsubscribe(
    tibjmsSession               session,
    const char*                 subscriberName);

extern tibjms_status
tibjmsSession_CreateTemporaryTopic(
    tibjmsSession               session,
    tibjmsTemporaryTopic*       tmpTopic);

extern tibjms_status
tibjmsSession_DeleteTemporaryTopic(
    tibjmsSession               session,
    tibjmsTemporaryTopic        tmpTopic);

extern tibjms_status
tibjmsSession_CreateTemporaryQueue(
    tibjmsSession               session,
    tibjmsTemporaryQueue*       tmpQueue);

extern tibjms_status
tibjmsSession_DeleteTemporaryQueue(
    tibjmsSession               session,
    tibjmsTemporaryQueue        tmpQueue);


extern tibjms_status
tibjmsTopicConnection_Create(
    tibjmsTopicConnection*              topicConnection,
    const char*                         brokerURL,
    const char*                         clientId,
    const char*                         username,
    const char*                         password);

extern tibjms_status
tibjmsTopicConnection_CreateTopicSession(
    tibjmsTopicConnection               topicConnection,
    tibjmsTopicSession*                 topicSession,
    tibjms_bool                         transacted,
    tibjmsAcknowledgeMode               ackowledgeMode);


extern tibjms_status
tibjmsQueueConnection_Create(
    tibjmsQueueConnection*              queueConnection,
    const char*                         brokerURL,
    const char*                         clientId,
    const char*                         username,
    const char*                         password);

extern tibjms_status
tibjmsQueueConnection_CreateQueueSession(
    tibjmsQueueConnection               queueConnection,
    tibjmsQueueSession*                 queueSession,
    tibjms_bool                         transacted,
    tibjmsAcknowledgeMode               acknowledgeMode);


extern tibjms_status
tibjmsTopicSession_CreateSubscriber(
    tibjmsTopicSession          session,
    tibjmsTopicSubscriber*      topicSubscriber,
    tibjmsTopic                 topic,
    const char*                 optionalSelector,
    tibjms_bool                 noLocal);

extern tibjms_status
tibjmsTopicSession_CreateDurableSubscriber(
    tibjmsTopicSession          session,
    tibjmsTopicSubscriber*      topicSubscriber,
    tibjmsTopic                 topic,
    const char*                 subscriberName,
    const char*                 optionalSelector,
    tibjms_bool                 noLocal);

extern tibjms_status
tibjmsTopicSession_CreatePublisher(
    tibjmsTopicSession          session,
    tibjmsTopicPublisher*       topicPublisher,
    tibjmsTopic                 topic);

extern tibjms_status
tibjmsTopicSession_Unsubscribe(
    tibjmsTopicSession          session,
    const char*                 subscriberName);

extern tibjms_status
tibjmsTopicSession_CreateTemporaryTopic(
    tibjmsTopicSession          session,
    tibjmsTemporaryTopic*       tmpTopic);

extern tibjms_status
tibjmsTopicSession_DeleteTemporaryTopic(
    tibjmsTopicSession          session,
    tibjmsTemporaryTopic        tmpTopic);


extern tibjms_status
tibjmsQueueSession_CreateBrowser(
    tibjmsQueueSession          session,
    tibjmsQueueBrowser*         browser,
    tibjmsQueue                 queue,
    const char*                 optionalSelector);

extern tibjms_status
tibjmsQueueSession_CreateReceiver(
    tibjmsQueueSession          session,
    tibjmsQueueReceiver*        queueReceiver,
    tibjmsQueue                 queue,
    const char*                 optionalSelector);

extern tibjms_status
tibjmsQueueSession_CreateSender(
    tibjmsQueueSession          session,
    tibjmsQueueSender*          queueSender,
    tibjmsQueue                 queue);

extern tibjms_status
tibjmsQueueSession_CreateTemporaryQueue(
    tibjmsQueueSession          session,
    tibjmsTemporaryQueue*       tmpQueue);

extern tibjms_status
tibjmsQueueSession_DeleteTemporaryQueue(
    tibjmsQueueSession          session,
    tibjmsTemporaryQueue        tmpQueue);


typedef struct __tibjmsMsgRequestor
{
    tibjmsSession               session;
    tibjmsDestination           sendDest;
    tibjmsDestination           receiveDest;
    tibjmsMsgProducer           producer;
    tibjmsMsgConsumer           consumer;

} _tibjmsMsgRequestorRec, *_tibjmsMsgRequestor;

extern tibjms_status
tibjmsQueueRequestor_Create(
    tibjmsQueueSession          session,
    tibjmsMsgRequestor*         msgRequestor,
    tibjmsQueue                 queue);

extern tibjms_status
tibjmsTopicRequestor_Create(
    tibjmsTopicSession          session,
    tibjmsMsgRequestor*         msgRequestor,
    tibjmsTopic                 topic);

extern tibjms_status
tibjmsMsgRequestor_Request(
    tibjmsMsgRequestor          msgRequestor,
    tibjmsMsg                   msgSent,
    tibjmsMsg*                  msgReply);

extern tibjms_status
tibjmsMsgRequestor_Close(
    tibjmsMsgRequestor          msgRequestor);


extern tibjms_status
tibjmsMsgProducer_Close(
    tibjmsMsgProducer           msgProducer);

extern tibjms_status
tibjmsMsgProducer_GetDeliveryMode(
    tibjmsMsgProducer           msgProducer,
    tibjms_int*                 deliveryMode);

extern tibjms_status
tibjmsMsgProducer_GetDisableMessageID(
    tibjmsMsgProducer           msgProducer,
    tibjms_bool*                doDisableMessageID);

extern tibjms_status
tibjmsMsgProducer_GetDisableMessageTimestamp(
    tibjmsMsgProducer           msgProducer,
    tibjms_bool*                doDisableMessageTimeStamp);

extern tibjms_status
tibjmsMsgProducer_GetPriority(
    tibjmsMsgProducer           msgProducer,
    tibjms_int*                 priority);

extern tibjms_status
tibjmsMsgProducer_GetTimeToLive(
    tibjmsMsgProducer           msgProducer,
    tibjms_long*                timeToLive);

extern tibjms_status
tibjmsMsgProducer_SetDeliveryMode(
    tibjmsMsgProducer           msgProducer,
    tibjms_int                  deliveryMode);

extern tibjms_status
tibjmsMsgProducer_SetDisableMessageID(
    tibjmsMsgProducer           msgProducer,
    tibjms_bool                 doDisableMessageID);

extern tibjms_status
tibjmsMsgProducer_SetDisableMessageTimestamp(
    tibjmsMsgProducer           msgProducer,
    tibjms_bool                 doDisableMessageTimeStamp);

extern tibjms_status
tibjmsMsgProducer_SetPriority(
    tibjmsMsgProducer           msgProducer,
    tibjms_int                  priority);

extern tibjms_status
tibjmsMsgProducer_SetTimeToLive(
    tibjmsMsgProducer           msgProducer,
    tibjms_long                 timeToLive);

extern tibjms_status
tibjmsMsgProducer_Send(
    tibjmsMsgProducer           msgProducer,
    tibjmsMsg                   msg);

extern tibjms_status
tibjmsMsgProducer_SendEx(
    tibjmsMsgProducer           msgProducer,
    tibjmsMsg                   msg,
    tibjms_int                  deliveryMode,
    tibjms_int                  priority,
    tibjms_long                 timeToLive);

extern tibjms_status
tibjmsMsgProducer_SendToDestination(
    tibjmsMsgProducer           msgProducer,
    tibjmsDestination           destination,
    tibjmsMsg                   msg);

extern tibjms_status
tibjmsMsgProducer_SendToDestinationEx(
    tibjmsMsgProducer           msgProducer,
    tibjmsDestination           destination,
    tibjmsMsg                   msg,
    tibjmsDeliveryMode          deliveryMode,
    tibjms_int                  priority,
    tibjms_long                 timeToLive);


extern tibjms_status
tibjmsTopicPublisher_GetTopic(
    tibjmsTopicPublisher        topicPublisher,
    tibjmsTopic*                topic);

extern tibjms_status
tibjmsTopicPublisher_Publish(
    tibjmsTopicPublisher        topicPublisher,
    tibjmsMsg                   msg);

extern tibjms_status
tibjmsTopicPublisher_PublishEx(
    tibjmsTopicPublisher        topicPublisher,
    tibjmsMsg                   msg,
    tibjms_int                  deliveryMode,
    tibjms_int                  priority,
    tibjms_long                 timeToLive);

extern tibjms_status
tibjmsTopicPublisher_PublishToTopic(
    tibjmsTopicPublisher        topicPublisher,
    tibjmsTopic                 topic,
    tibjmsMsg                   msg);

extern tibjms_status
tibjmsTopicPublisher_PublishToTopicEx(
    tibjmsTopicPublisher        topicPublisher,
    tibjmsTopic                 topic,
    tibjmsMsg                   msg,
    tibjmsDeliveryMode          deliveryMode,
    tibjms_int                  priority,
    tibjms_long                 timeToLive);


extern tibjms_status
tibjmsQueueSender_GetQueue(
    tibjmsQueueSender           queueSender,
    tibjmsQueue*                queue);

extern tibjms_status
tibjmsQueueSender_Send(
    tibjmsQueueSender           queueSender,
    tibjmsMsg                   msg);

extern tibjms_status
tibjmsQueueSender_SendEx(
    tibjmsQueueSender           queueSender,
    tibjmsMsg                   msg,
    tibjms_int                  deliveryMode,
    tibjms_int                  priority,
    tibjms_long                 timeToLive);

extern tibjms_status
tibjmsQueueSender_SendToQueue(
    tibjmsQueueSender           queueSender,
    tibjmsQueue                 queue,
    tibjmsMsg                   msg);

extern tibjms_status
tibjmsQueueSender_SendToQueueEx(
    tibjmsQueueSender           queueSender,
    tibjmsQueue                 queue,
    tibjmsMsg                   msg,
    tibjmsDeliveryMode          deliveryMode,
    tibjms_int                  priority,
    tibjms_long                 timeToLive);


typedef void
(*tibjmsMsgCallback) (
    tibjmsMsgConsumer   msgConsumer,
    tibjmsMsg           msg,
    void*               closure);

extern tibjms_status
tibjmsMsgConsumer_Close(
    tibjmsMsgConsumer           msgConsumer);

extern tibjms_status
tibjmsMsgConsumer_GetMsgSelector(
    tibjmsMsgConsumer           msgConsumer,
    const char**                selectorPtr);

extern tibjms_status
tibjmsMsgConsumer_Receive(
    tibjmsMsgConsumer           msgConsumer,
    tibjmsMsg*                  msg);

extern tibjms_status
tibjmsMsgConsumer_ReceiveTimeout(
    tibjmsMsgConsumer           msgConsumer,
    tibjmsMsg*                  msg,
    tibjms_long                 timeout);

extern tibjms_status
tibjmsMsgConsumer_ReceiveNoWait(
    tibjmsMsgConsumer           msgConsumer,
    tibjmsMsg*                  msg);

extern tibjms_status
tibjmsMsgConsumer_SetMsgListener(
    tibjmsMsgConsumer           msgConsumer,
    tibjmsMsgCallback           callback,
    void*                       closure);

extern tibjms_status
tibjmsMsgConsumer_GetMsgListener(
    tibjmsMsgConsumer           msgConsumer,
    tibjmsMsgCallback*          callbackPtr,
    void**                      closure);


extern tibjms_status
tibjmsTopicSubscriber_GetTopic(
    tibjmsTopicSubscriber       topicSubscriber,
    tibjmsTopic*                topic);

extern tibjms_status
tibjmsTopicSubscriber_GetNoLocal(
    tibjmsTopicSubscriber       topicSubscriber,
    tibjms_bool*                isNoLocal);


extern tibjms_status
tibjmsQueueReceiver_GetQueue(
    tibjmsQueueReceiver         queueReceiver,
    tibjmsQueue*                queue);


extern tibjms_status
tibjmsMsg_Create(
    tibjmsMsg*          message);

extern tibjms_status
tibjmsMsg_Destroy(
    tibjmsMsg           message);

/* get message type */
extern tibjms_status
tibjmsMsg_GetType(
    tibjmsMsg           message,
    tibjmsMsgType*      type);

/* From JMS specification */

extern tibjms_status
tibjmsMsg_Acknowledge(
    tibjmsMsg           message);

extern tibjms_status
tibjmsMsg_ClearBody(
    tibjmsMsg           message);

extern tibjms_status
tibjmsMsg_ClearProperties(
    tibjmsMsg           message);

extern tibjms_status
tibjmsMsg_GetPropertyNames(
    tibjmsMsg           message,
    tibjmsMsgEnum*      enumeration);

/* returns TIBJMS_NOT_FOUND if end of enumeration */
extern tibjms_status
tibjmsMsgEnum_GetNextName(
    tibjmsMsgEnum       enumeration,
    const char**        name);

extern tibjms_status
tibjmsMsgEnum_Destroy(
    tibjmsMsgEnum       enumeration);

extern tibjms_status
tibjmsMsg_PropertyExists(
    tibjmsMsg           message,
    const char*         name,
    tibjms_bool*        answer);

extern tibjms_status
tibjmsMsg_GetProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjmsMsgField*     data);

/* Gets and Sets on Properties */

extern tibjms_status
tibjmsMsg_GetBooleanProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_bool*        value);

extern tibjms_status
tibjmsMsg_GetByteProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_byte*        value);

extern tibjms_status
tibjmsMsg_GetDoubleProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_double*      value);

extern tibjms_status
tibjmsMsg_GetFloatProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_float*       value);

extern tibjms_status
tibjmsMsg_GetIntProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_int*         value);

extern tibjms_status
tibjmsMsg_GetLongProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_long*        value);

extern tibjms_status
tibjmsMsg_GetShortProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_short*       value);

extern tibjms_status
tibjmsMsg_GetStringProperty(
    tibjmsMsg           message,
    const char*         name,
    const char**        value);

extern tibjms_status
tibjmsMsg_SetBooleanProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_bool         value);

extern tibjms_status
tibjmsMsg_SetByteProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_byte         value);

extern tibjms_status
tibjmsMsg_SetDoubleProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_double       value);

extern tibjms_status
tibjmsMsg_SetFloatProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_float        value);

extern tibjms_status
tibjmsMsg_SetIntProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_int          value);

extern tibjms_status
tibjmsMsg_SetLongProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_long         value);

extern tibjms_status
tibjmsMsg_SetShortProperty(
    tibjmsMsg           message,
    const char*         name,
    tibjms_short        value);

extern tibjms_status
tibjmsMsg_SetStringProperty(
    tibjmsMsg           message,
    const char*         name,
    const char*         value);

/* Message Headers */

extern tibjms_status
tibjmsMsg_GetJMSCorrelationID(
    tibjmsMsg           message,
    const char**        value);

extern tibjms_status
tibjmsMsg_GetJMSDeliveryMode(
    tibjmsMsg           message,
    tibjmsDeliveryMode* value);

extern tibjms_status
tibjmsMsg_GetJMSDestination(
    tibjmsMsg           message,
    tibjmsDestination*  value);

extern tibjms_status
tibjmsMsg_GetJMSExpiration(
    tibjmsMsg           message,
    tibjms_long*        value);

extern tibjms_status
tibjmsMsg_GetJMSMessageID(
    tibjmsMsg           message,
    const char**        value);

extern tibjms_status
tibjmsMsg_GetJMSPriority(
    tibjmsMsg           message,
    tibjms_int*         value); 

extern tibjms_status
tibjmsMsg_GetJMSRedelivered(
    tibjmsMsg           message,
    tibjms_bool*        value);

extern tibjms_status
tibjmsMsg_GetJMSReplyTo(
    tibjmsMsg           message,
    tibjmsDestination*  value);

extern tibjms_status
tibjmsMsg_GetJMSTimestamp(
    tibjmsMsg           message,
    tibjms_long*        value);

extern tibjms_status
tibjmsMsg_GetJMSType(
    tibjmsMsg           message,
    const char**        value);

extern tibjms_status
tibjmsMsg_SetJMSCorrelationID(
    tibjmsMsg           message,
    const char*         value);

extern tibjms_status
tibjmsMsg_SetJMSDeliveryMode(
    tibjmsMsg           message,
    tibjmsDeliveryMode  value);

extern tibjms_status
tibjmsMsg_SetJMSDestination(
    tibjmsMsg           message,
    tibjmsDestination   value);

extern tibjms_status
tibjmsMsg_SetJMSExpiration(
    tibjmsMsg           message,
    tibjms_long         value);

extern tibjms_status
tibjmsMsg_SetJMSMessageID(
    tibjmsMsg           message,
    const char*         value);

extern tibjms_status
tibjmsMsg_SetJMSPriority(
    tibjmsMsg           message,
    tibjms_int          value); 

extern tibjms_status
tibjmsMsg_SetJMSRedelivered(
    tibjmsMsg           message,
    tibjms_bool         value);

extern tibjms_status
tibjmsMsg_SetJMSReplyTo(
    tibjmsMsg           message,
    tibjmsDestination   value);

extern tibjms_status
tibjmsMsg_SetJMSTimestamp(
    tibjmsMsg           message,
    tibjms_long         value);

extern tibjms_status
tibjmsMsg_SetJMSType(
    tibjmsMsg           message,
    const char*         value);

/*
 * DEPRECATION NOTICE
 *
 * The following function is deprecated.  Any use of a deprecated
 * feature should be discontinued as it may be removed in a future
 * release. You should avoid becoming dependent on deprecated 
 * features and become familiar with the equivalent replacement feature.
 *
 * This function will disappear.  You should use tibjmsMsg_GetByteSize()
 * instead.
 *
 */
extern tibjms_int
tibjmsMsg_ByteSize(
    tibjmsMsg           message);

extern tibjms_status
tibjmsMsg_GetEncoding(
    const tibjmsMsg     msg,
    const char**        value);

extern tibjms_status
tibjmsMsg_SetEncoding(
    tibjmsMsg           msg,
    const char*         value);

extern tibjms_status
tibjmsMsg_GetByteSize(
    tibjmsMsg           msg,
    tibjms_int*         size);

extern tibjms_status
tibjmsMsg_GetAsBytes(
    const tibjmsMsg     msg,
    const void**        bytes,
    tibjms_int*         actual_size);

extern tibjms_status
tibjmsMsg_GetAsBytesCopy(
    const tibjmsMsg msg,
    void*           bytes,
    tibjms_int      avail_size,
    tibjms_int*     actual_size);

extern tibjms_status
tibjmsMsg_CreateFromBytes(
    tibjmsMsg*      msgPtr,
    const void*     bytes);

/* make a read-only message writeable again -  NOT PART OF JMS SPEC  */
extern tibjms_status
tibjmsMsg_MakeWriteable(
    tibjmsMsg           msg);


/* make a copy of an existing message */
tibjms_status
tibjmsMsg_CreateCopy(
    const tibjmsMsg     msg,
    tibjmsMsg*          copy);

/* Prints message, for debugging purposes only */
extern void
tibjmsMsg_Print(
    tibjmsMsg           message);

extern void
tibjmsMsg_PrintFile(
    tibjmsMsg           message,
    FILE*               file);

extern void
tibjmsMsgField_Print(
    tibjmsMsgField*     field);

extern void
tibjmsMsgField_PrintFile(
    tibjmsMsgField*     field,
    FILE*               file);


extern tibjms_status
tibjmsTextMsg_Create(
    tibjmsTextMsg*      message);

extern tibjms_status
tibjmsTextMsg_GetText(
    tibjmsTextMsg       message,
    const char**        text);

extern tibjms_status
tibjmsTextMsg_SetText(
    tibjmsTextMsg       message,
    const char*         text);


extern tibjms_status
tibjmsBytesMsg_Create(
    tibjmsBytesMsg*     message);

extern tibjms_status
tibjmsBytesMsg_GetBodyLength(
    tibjmsMsg           msg,
    tibjms_int*         return_length);
        
extern tibjms_status
tibjmsBytesMsg_ReadBoolean(
    tibjmsBytesMsg      message,
    tibjms_bool*        value);

extern tibjms_status
tibjmsBytesMsg_ReadByte(
    tibjmsBytesMsg      message,
    tibjms_byte*        value);

extern tibjms_status
tibjmsBytesMsg_ReadBytes(
    tibjmsBytesMsg      message,
    const void**        value,
    tibjms_int          requested_length,
    tibjms_int*         return_length);

extern tibjms_status
tibjmsBytesMsg_ReadChar(
    tibjmsBytesMsg      message,
    tibjms_wchar*       value);

extern tibjms_status
tibjmsBytesMsg_ReadDouble(
    tibjmsBytesMsg      message,
    tibjms_double*      value);

extern tibjms_status
tibjmsBytesMsg_ReadFloat(
    tibjmsBytesMsg      message,
    tibjms_float*       value);

extern tibjms_status
tibjmsBytesMsg_ReadInt(
    tibjmsBytesMsg      message,
    tibjms_int*         value);

extern tibjms_status
tibjmsBytesMsg_ReadLong(
    tibjmsBytesMsg      message,
    tibjms_long*        value);

extern tibjms_status
tibjmsBytesMsg_ReadShort(
    tibjmsBytesMsg      message,
    tibjms_short*       value);

extern tibjms_status
tibjmsBytesMsg_ReadUnsignedByte(
    tibjmsBytesMsg      message,
    tibjms_int*         value);

extern tibjms_status
tibjmsBytesMsg_ReadUnsignedShort(
    tibjmsBytesMsg      message,
    tibjms_int*         value);

extern tibjms_status
tibjmsBytesMsg_ReadUTF(
    tibjmsBytesMsg      message,
    const char**        value,
    tibjms_int*         length);

extern tibjms_status
tibjmsBytesMsg_WriteBoolean(
    tibjmsBytesMsg      message,
    tibjms_bool         value);

extern tibjms_status
tibjmsBytesMsg_WriteByte(
    tibjmsBytesMsg      message,
    tibjms_byte         value);

extern tibjms_status
tibjmsBytesMsg_WriteBytes(
    tibjmsBytesMsg      message,
    const void*         value,
    tibjms_uint         size);

extern tibjms_status
tibjmsBytesMsg_WriteChar(
    tibjmsBytesMsg      message,
    tibjms_wchar        value);

extern tibjms_status
tibjmsBytesMsg_WriteDouble(
    tibjmsBytesMsg      message,
    tibjms_double       value);

extern tibjms_status
tibjmsBytesMsg_WriteFloat(
    tibjmsBytesMsg      message,
    tibjms_float        value);

extern tibjms_status
tibjmsBytesMsg_WriteInt(
    tibjmsBytesMsg      message,
    tibjms_int          value);

extern tibjms_status
tibjmsBytesMsg_WriteLong(
    tibjmsBytesMsg      message,
    tibjms_long         value);

extern tibjms_status
tibjmsBytesMsg_WriteShort(
    tibjmsBytesMsg      message,
    tibjms_short        value);

extern tibjms_status
tibjmsBytesMsg_WriteUTF(
    tibjmsBytesMsg      message,
    const char*         value);

extern tibjms_status
tibjmsBytesMsg_Reset(
    tibjmsBytesMsg      message);

extern tibjms_status
tibjmsBytesMsg_GetBytes(
    tibjmsBytesMsg      message,
    void**              bytes,
    tibjms_uint*        byteSize);

extern tibjms_status
tibjmsBytesMsg_SetBytes(
    tibjmsBytesMsg      message,
    const void*         bytes,
    tibjms_uint         byteSize);


extern tibjms_status
tibjmsStreamMsg_Create(
    tibjmsStreamMsg*    message);

extern tibjms_status
tibjmsStreamMsg_ReadField(
    tibjmsStreamMsg     message,
    tibjmsMsgField*     value);

extern tibjms_status
tibjmsStreamMsg_ReadBoolean(
    tibjmsStreamMsg     message,
    tibjms_bool*        value);

extern tibjms_status
tibjmsStreamMsg_ReadByte(
    tibjmsStreamMsg     message,
    tibjms_byte*        value);

extern tibjms_status
tibjmsStreamMsg_ReadBytes(
    tibjmsStreamMsg     message,
    void**              value,
    tibjms_uint*        size);

extern tibjms_status
tibjmsStreamMsg_ReadChar(
    tibjmsStreamMsg     message,
    tibjms_wchar*       value);

extern tibjms_status
tibjmsStreamMsg_ReadDouble(
    tibjmsStreamMsg     message,
    tibjms_double*      value);

extern tibjms_status
tibjmsStreamMsg_ReadFloat(
    tibjmsStreamMsg     message,
    tibjms_float*       value);

extern tibjms_status
tibjmsStreamMsg_ReadInt(
    tibjmsStreamMsg     message,
    tibjms_int*         value);

extern tibjms_status
tibjmsStreamMsg_ReadLong(
    tibjmsStreamMsg     message,
    tibjms_long*        value);

extern tibjms_status
tibjmsStreamMsg_ReadShort(
    tibjmsStreamMsg     message,
    tibjms_short*       value);

extern tibjms_status
tibjmsStreamMsg_ReadString(
    tibjmsStreamMsg     message,
    char**              value);

extern tibjms_status
tibjmsStreamMsg_Reset(
    tibjmsStreamMsg     message);

extern tibjms_status
tibjmsStreamMsg_WriteBoolean(
    tibjmsStreamMsg     message,
    tibjms_bool         value);

extern tibjms_status
tibjmsStreamMsg_WriteByte(
    tibjmsStreamMsg     message,
    tibjms_byte         value);

extern tibjms_status
tibjmsStreamMsg_WriteBytes(
    tibjmsStreamMsg     message,
    void*               value,
    tibjms_uint         size);

extern tibjms_status
tibjmsStreamMsg_WriteChar(
    tibjmsStreamMsg     message,
    tibjms_wchar        value);

extern tibjms_status
tibjmsStreamMsg_WriteDouble(
    tibjmsStreamMsg     message,
    tibjms_double       value);

extern tibjms_status
tibjmsStreamMsg_WriteFloat(
    tibjmsStreamMsg     message,
    tibjms_float        value);

extern tibjms_status
tibjmsStreamMsg_WriteInt(
    tibjmsStreamMsg     message,
    tibjms_int          value);

extern tibjms_status
tibjmsStreamMsg_WriteLong(
    tibjmsStreamMsg     message,
    tibjms_long         value);

extern tibjms_status
tibjmsStreamMsg_WriteShort(
    tibjmsStreamMsg     message,
    tibjms_short        value);

extern tibjms_status
tibjmsStreamMsg_WriteString(
    tibjmsStreamMsg     message,
    char*               value);

extern tibjms_status
tibjmsStreamMsg_WriteShortArray(
    tibjmsMsg           msg,
    const tibjms_short* value,
    tibjms_int          count);

extern tibjms_status
tibjmsStreamMsg_WriteIntArray(
    tibjmsMsg           msg,
    const tibjms_int*   value,
    tibjms_int          count);

extern tibjms_status
tibjmsStreamMsg_WriteLongArray(
    tibjmsMsg           msg,
    const tibjms_long*  value,
    tibjms_int          count);

extern tibjms_status
tibjmsStreamMsg_WriteFloatArray(
    tibjmsMsg           msg,
    const tibjms_float* value,
    tibjms_int          count);

extern tibjms_status
tibjmsStreamMsg_WriteDoubleArray(
    tibjmsMsg           msg,
    const tibjms_double* value,
    tibjms_int          count);

extern tibjms_status
tibjmsStreamMsg_WriteMapMsg(
    tibjmsMsg           msg,
    tibjmsMsg		value);

extern tibjms_status
tibjmsStreamMsg_WriteStreamMsg(
    tibjmsMsg           msg,
    tibjmsMsg		value);

extern void
tibjmsStreamMsg_FreeField(
    tibjmsMsgField*     field);

extern tibjms_status
tibjmsObjectMsg_Create(
    tibjmsObjectMsg*    message);

extern tibjms_status
tibjmsObjectMsg_GetObjectBytes(
    tibjmsObjectMsg     message,
    void**              bytes,
    tibjms_uint*        byteSize);

extern tibjms_status
tibjmsObjectMsg_SetObjectBytes(
    tibjmsObjectMsg     message,
    const void*         bytes,
    tibjms_uint         byteSize);


extern tibjms_status
tibjmsMapMsg_Create(
    tibjmsMapMsg*       message);

extern tibjms_status
tibjmsMapMsg_GetBoolean(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_bool*        value);

extern tibjms_status
tibjmsMapMsg_GetByte(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_byte*        value);

extern tibjms_status
tibjmsMapMsg_GetBytes(
    tibjmsMapMsg        message,
    const char*         name,
    const void**        bytes,
    tibjms_uint*        bytesSize);

extern tibjms_status
tibjmsMapMsg_GetChar(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_wchar*       value);

extern tibjms_status
tibjmsMapMsg_GetDouble(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_double*      value);

extern tibjms_status
tibjmsMapMsg_GetFloat(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_float*       value);

extern tibjms_status
tibjmsMapMsg_GetInt(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_int*         value);

extern tibjms_status
tibjmsMapMsg_GetLong(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_long*        value);

extern tibjms_status
tibjmsMapMsg_GetShort(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_short*       value);

extern tibjms_status
tibjmsMapMsg_GetString(
    tibjmsMapMsg        message,
    const char*         name,
    const char**        value);

extern tibjms_status
tibjmsMapMsg_GetMapMsg(
    tibjmsMapMsg        msg,
    const char*         name,
    tibjmsMapMsg*       value);

extern tibjms_status
tibjmsMapMsg_SetBoolean(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_bool         value);

extern tibjms_status
tibjmsMapMsg_SetByte(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_byte         value);

extern tibjms_status
tibjmsMapMsg_SetBytes(
    tibjmsMapMsg        message,
    const char*         name,
    void*               bytes,
    tibjms_uint         bytesSize);

extern tibjms_status
tibjmsMapMsg_SetReferencedBytes(
    tibjmsMapMsg        message,
    const char*         name,
    void*               bytes,
    tibjms_uint         bytesSize);

extern tibjms_status
tibjmsMapMsg_SetChar(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_wchar        value);

extern tibjms_status
tibjmsMapMsg_SetDouble(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_double       value);

extern tibjms_status
tibjmsMapMsg_SetFloat(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_float        value);

extern tibjms_status
tibjmsMapMsg_SetInt(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_int          value);

extern tibjms_status
tibjmsMapMsg_SetLong(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_long         value);

extern tibjms_status
tibjmsMapMsg_SetShort(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_short        value);

extern tibjms_status
tibjmsMapMsg_SetString(
    tibjmsMapMsg        message,
    const char*         name,
    const char*         value);

extern tibjms_status
tibjmsMapMsg_SetMapMsg(
    tibjmsMsg           msg,
    const char*         name,
    tibjmsMsg           mapMsg,
    tibjms_bool         takeOwnership);

extern tibjms_status
tibjmsMapMsg_SetStreamMsg(
    tibjmsMsg           msg,
    const char*         name,
    tibjmsMsg           streamMsg,
    tibjms_bool         takeOwnership);

extern tibjms_status
tibjmsMapMsg_SetShortArray(
    tibjmsMsg           msg,
    const char*         name,
    const tibjms_short* value,
    tibjms_uint         count);

extern tibjms_status
tibjmsMapMsg_SetIntArray(
    tibjmsMsg           msg,
    const char*         name,
    const tibjms_int*   value,
    tibjms_uint         count);

extern tibjms_status
tibjmsMapMsg_SetLongArray(
    tibjmsMsg           msg,
    const char*         name,
    const tibjms_long*  value,
    tibjms_uint         count);

extern tibjms_status
tibjmsMapMsg_SetFloatArray(
    tibjmsMsg           msg,
    const char*         name,
    const tibjms_float* value,
    tibjms_uint         count);

extern tibjms_status
tibjmsMapMsg_SetDoubleArray(
    tibjmsMsg               msg,
    const char*             name,
    const tibjms_double*    value,
    tibjms_uint             count);

extern tibjms_status
tibjmsMapMsg_ItemExists(
    tibjmsMapMsg        message,
    const char*         name,
    tibjms_bool*        answer);

extern tibjms_status
tibjmsMapMsg_GetMapNames(
    tibjmsMsg           message,
    tibjmsMsgEnum*      enumeration);

extern tibjms_status
tibjmsMapMsg_GetField(
    tibjmsMapMsg        message,
    const char*         name,
    tibjmsMsgField*     data);


extern tibjms_status
tibjmsQueueBrowser_GetQueue(
    tibjmsQueueBrowser          queueBrowser,
    tibjmsQueue*                queue);

extern tibjms_status
tibjmsQueueBrowser_GetMsgSelector(
    tibjmsQueueBrowser          queueBrowser,
    const char**                selector);

extern tibjms_status
tibjmsQueueBrowser_GetNext(
    tibjmsQueueBrowser          queueBrowser,
    tibjmsMsg*                  msg);

extern tibjms_status
tibjmsQueueBrowser_Close(
    tibjmsQueueBrowser          queueBrowser);


/*
 * XID structure id defined in X/Open xa.h header file.
 */
#ifndef XA_H
typedef struct xid_t XID;
#define XA_H
#endif


/*
 * JMS XA object C API.
 */

extern tibjms_status
tibjmsXAConnection_Create(
    tibjmsConnection*           connection,
    const char*                 brokerURL,
    const char*                 clientId,
    const char*                 username,
    const char*                 password);

extern tibjms_status
tibjmsXAConnection_CreateSSL(
    tibjmsConnection*           connection,
    const char*                 brokerURL,
    const char*                 clientId,
    const char*                 username,
    const char*                 password,
    tibjmsSSLParams             params,
    const char*                 pk_password);

extern tibjms_status
tibjmsXAConnection_CreateXASession(
    tibjmsConnection            connection,
    tibjmsSession*              session);

extern tibjms_status
tibjmsXAConnection_Close(
    tibjmsConnection            connection);

extern tibjms_status
tibjmsXASession_Close(
    tibjmsSession               session);

extern tibjms_status
tibjmsXASession_GetSession(
    tibjmsSession               xaSession,
    tibjmsSession*              session);

extern tibjms_status
tibjmsXASession_GetXAResource(
    tibjmsSession               session,
    tibjmsXAResource*           xaResource);

/*
 * Extensions for Classic X/Open XA.
 *
 * If an xa_info string was passed in to the xa_open function then there is no
 * need to create an XAConnection or an XASession as they will have been
 * created by the xa_open call. Use the functions below to obtain these
 * objects. The objects are deleted by xa_close so it is an error to close
 * them explicitly.
 */

extern tibjms_status
tibjmsXAConnection_Get(
    tibjmsConnection*           connection,
    const char*                 brokerURL);

extern tibjms_status
tibjmsXAConnection_GetXASession(
    tibjmsConnection            connection,
    tibjmsSession*              xaSession);


/*
 * JTA XAResource object C API.
 */

extern tibjms_status
tibjmsXAResource_Commit(
    tibjmsXAResource            xaResource,
    XID*                        xid,
    tibjms_bool                 onePhase);

extern tibjms_status
tibjmsXAResource_End(
    tibjmsXAResource            xaResource,
    XID*                        xid,
    int                         flags);

extern tibjms_status
tibjmsXAResource_Forget(
    tibjmsXAResource            xaResource,
    XID*                        xid);

extern tibjms_status
tibjmsXAResource_GetTransactionTimeout(
    tibjmsXAResource            xaResource,
    tibjms_int*                 seconds);

extern tibjms_status
tibjmsXAResource_isSameRM(
    tibjmsXAResource            xaResource,
    tibjmsXAResource            xaResource2,
    tibjms_bool*                result);

extern tibjms_status
tibjmsXAResource_Prepare(
    tibjmsXAResource            xaResource,
    XID*                        xid);

extern tibjms_status
tibjmsXAResource_Recover(
    tibjmsXAResource            xaResource,
    XID*                        xids,
    tibjms_int                  desiredCount,
    tibjms_int*                 returnedCount,
    tibjms_int                  flag);

extern tibjms_status
tibjmsXAResource_Rollback(
    tibjmsXAResource            xaResource,
    XID*                        xid);

extern tibjms_status
tibjmsXAResource_SetTransactionTimeout(
    tibjmsXAResource            xaResource,
    tibjms_int                  seconds);

extern tibjms_status
tibjmsXAResource_Start(
    tibjmsXAResource            xaResource,
    XID*                        xid,
    tibjms_int                  flags);

/*
 * Extension for mapping from Classic X/Open XA to JTA.
 *
 * Setting an RMID for an XAResource object identifies the XAResource object
 * to the "xa_" functions in the Classic X/Open XA interface.  The association
 * between a given RMID and the XAResource object is broken under the
 * following conditions:
 *
 *  closing the related XA Session object
 *  closing the related XA Connection object
 */
extern tibjms_status
tibjmsXAResource_SetRMID(
    tibjmsXAResource            xaResource,
    tibjms_int                  rmid);

extern tibjms_status
tibjmsXAResource_GetRMID(
    tibjmsXAResource            xaResource,
    tibjms_int*                 rmid);


#define TIBJMS_SSL_TRACE_ENV            "TIBJMS_SSL_TRACE"
#define TIBJMS_SSL_DEBUG_TRACE_ENV      "TIBJMS_SSL_DEBUG_TRACE"

#define TIBJMS_SSL_ENCODING_AUTO        (0x0000)
#define TIBJMS_SSL_ENCODING_PEM         (0x0001)
#define TIBJMS_SSL_ENCODING_DER         (0x0002)
#define TIBJMS_SSL_ENCODING_BER         (0x0004)
#define TIBJMS_SSL_ENCODING_PKCS7       (0x0010)
#define TIBJMS_SSL_ENCODING_PKCS8       (0x0020)
#define TIBJMS_SSL_ENCODING_PKCS12      (0x0040)
#define TIBJMS_SSL_ENCODING_ENTRUST     (0x0100)
#define TIBJMS_SSL_ENCODING_KEYSTORE    (0x0200)

/*
 * DEPRECATION NOTICE
 *
 * The following two constants are deprecated.  Any use of a deprecated
 * feature should be discontinued as it may be removed in a future
 * release. You should avoid becoming dependent on deprecated 
 * features.
 *
 */
#define TIBJMS_SSL_MIN_RENEGOTIATE_SIZE       (64L*1024L) /* bytes */
#define TIBJMS_SSL_MIN_RENEGOTIATE_INTERVAL   (15) /* in seconds */

typedef tibjms_status
(*tibjmsSSLHostNameVerifier) (
    const char*     connected_hostname,
    const char*     expected_hostname,
    const char*     certificate_name,
    void*           closure);

extern const char*
tibjmsSSL_OpenSSLVersion(
    char*       buffer,
    tibjms_int  bufsize);

extern void
tibjmsSSL_SetTrace(
    tibjms_bool             trace);

extern void
tibjmsSSL_SetDebugTrace(
    tibjms_bool             trace);

extern tibjms_bool
tibjmsSSL_GetTrace(void);

extern tibjms_bool
tibjmsSSL_GetDebugTrace(void);

extern tibjmsSSLParams
tibjmsSSLParams_Create(void);

extern void
tibjmsSSLParams_Destroy(
    tibjmsSSLParams         params);

extern tibjms_status
tibjmsSSLParams_SetCiphers(
    tibjmsSSLParams         params,
    const char*             ciphers);

extern tibjms_status
tibjmsSSLParams_SetIdentity(
    tibjmsSSLParams         params,
    const void*             data,
    tibjms_int              size,
    tibjms_int              encoding);

extern tibjms_status
tibjmsSSLParams_GetIdentity(
    tibjmsSSLParams         params,
    const void**            data,
    tibjms_int*             size,
    tibjms_int*             encoding);

extern tibjms_status
tibjmsSSLParams_SetIdentityFile(
    tibjmsSSLParams         params,
    const char*             filename,
    tibjms_int              encoding);

extern tibjms_status
tibjmsSSLParams_SetCRLPath(
    tibjmsSSLParams         params,
    const char*             crl_path);

extern tibjms_status
tibjmsSSLParams_SetCRLUpdateInterval(
    tibjmsSSLParams         params,
    tibjms_int              hours);

extern tibjms_status
tibjmsSSLParams_AddIssuerCert(
    tibjmsSSLParams         params,
    const void*             data,
    tibjms_int              size,
    tibjms_int              encoding);

extern tibjms_status
tibjmsSSLParams_AddIssuerCertFile(
    tibjmsSSLParams         params,
    const char*             filename,
    tibjms_int              encoding);

extern tibjms_status
tibjmsSSLParams_SetPrivateKey(
    tibjmsSSLParams         params,
    const void*             data,
    tibjms_int              size,
    tibjms_int              encoding);

extern tibjms_status
tibjmsSSLParams_GetPrivateKey(
    tibjmsSSLParams         params,
    const void**            data,
    tibjms_int*             size,
    tibjms_int*             encoding);

extern tibjms_status
tibjmsSSLParams_SetPrivateKeyFile(
    tibjmsSSLParams         params,
    const char*             filename,
    tibjms_int              encoding);

extern tibjms_status
tibjmsSSLParams_AddTrustedCert(
    tibjmsSSLParams         params,
    const void*             data,
    tibjms_int              size,
    tibjms_int              encoding);

extern tibjms_status
tibjmsSSLParams_AddTrustedCertFile(
    tibjmsSSLParams         params,
    const char*             filename,
    tibjms_int              encoding);

extern tibjms_status
tibjmsSSLParams_SetVerifyHost(
    tibjmsSSLParams         params,
    tibjms_bool             verify);

extern tibjms_status
tibjmsSSLParams_SetAuthOnly(
    tibjmsSSLParams         params,
    tibjms_bool             auth_only);

extern tibjms_status
tibjmsSSLParams_SetVerifyHostName(
    tibjmsSSLParams         params,
    tibjms_bool             verify);

extern tibjms_status
tibjmsSSLParams_SetHostNameVerifier(
    tibjmsSSLParams         params,
    tibjmsSSLHostNameVerifier verifier,
    const void*             closure);

extern tibjms_status
tibjmsSSLParams_SetExpectedHostName(
    tibjmsSSLParams         params,
    const char*             expected_hostname);

/*
 * DEPRECATION NOTICE
 *
 * The following function is deprecated.  Any use of a deprecated
 * feature should be discontinued as it may be removed in a future
 * release. You should avoid becoming dependent on deprecated 
 * features.
 *
 */
extern tibjms_status
tibjmsSSLParams_SetRenegotiateInterval(
    tibjmsSSLParams         params,
    tibjms_long             milliseconds);

/*
 * DEPRECATION NOTICE
 *
 * The following function is deprecated.  Any use of a deprecated
 * feature should be discontinued as it may be removed in a future
 * release. You should avoid becoming dependent on deprecated 
 * features.
 *
 */
extern tibjms_status
tibjmsSSLParams_SetRenegotiateSize(
    tibjmsSSLParams         params,
    tibjms_long             bytes);

extern tibjms_status
tibjmsSSLParams_SetRandFile(
    tibjmsSSLParams         params,
    const char*             rand_file);

extern tibjms_status
tibjmsSSLParams_SetRandEGD(
    tibjmsSSLParams         params,
    const char*             rand_egd_path);

extern tibjms_status
tibjmsSSLParams_SetRandData(
    tibjmsSSLParams         params,
    const char*             rand_data,
    tibjms_int              size);

extern tibjms_status
tibjmsConnection_CreateSSL(
    tibjmsConnection*       connection,
    const char*             brokerURL,
    const char*             clientId,
    const char*             username,
    const char*             password,
    tibjmsSSLParams         params,
    const char*             pk_password);

extern tibjms_status
tibjmsQueueConnection_CreateSSL(
    tibjmsQueueConnection*  queueConnection,
    const char*             brokerURL,
    const char*             clientId,
    const char*             username,
    const char*             password,
    tibjmsSSLParams         params,
    const char*             pk_password);

extern tibjms_status
tibjmsTopicConnection_CreateSSL(
    tibjmsTopicConnection*  topicConnection,
    const char*             brokerURL,
    const char*             clientId,
    const char*             username,
    const char*             password,
    tibjmsSSLParams         params,
    const char*             pk_password);


/* All the connection factory object are the same with a type identifier */
typedef struct __tibjmsConnectionFactory*       tibjmsConnectionFactory;
typedef struct __tibjmsConnectionFactory*       tibjmsTopicConnectionFactory;
typedef struct __tibjmsConnectionFactory*       tibjmsQueueConnectionFactory;
typedef struct __tibjmsConnectionFactory*       tibjmsXAConnectionFactory;
typedef struct __tibjmsConnectionFactory*       tibjmsXATopicConnectionFactory;
typedef struct __tibjmsConnectionFactory*       tibjmsXAQueueConnectionFactory;


/*
 * connection factory types returned by tibjmsConnectionFactory_GetType
 */
typedef enum  __tibjmsConnectionFactoryType
{
    TIBJMS_CONNECTION_FACTORY           = 0,   /* should match TIBJMS_UNKNOWN etc*/
    TIBJMS_QUEUE_CONNECTION_FACTORY     = 1,
    TIBJMS_TOPIC_CONNECTION_FACTORY     = 2,
    TIBJMS_XA_CONNECTION_FACTORY        = 3,
    TIBJMS_XA_QUEUE_CONNECTION_FACTORY  = 4,
    TIBJMS_XA_TOPIC_CONNECTION_FACTORY  = 5

} tibjmsConnectionFactoryType;

/* destroy the connection factory */
extern tibjms_status
tibjmsConnectionFactory_Destroy(
    tibjmsConnectionFactory             factory);

extern tibjms_status
tibjmsConnectionFactory_GetType(
    tibjmsConnectionFactory             factory,
    tibjmsConnectionFactoryType*        type);

extern tibjms_status
tibjmsConnectionFactory_CreateConnection(
    tibjmsConnectionFactory             factory,
    tibjmsConnection*                   connection,
    const char *                        username,
    const char *                        password);


extern tibjms_status
tibjmsTopicConnectionFactory_CreateConnection(
    tibjmsTopicConnectionFactory        factory,
    tibjmsTopicConnection*              connection,
    const char *                        username,
    const char *                        password);


extern tibjms_status
tibjmsQueueConnectionFactory_CreateConnection(
    tibjmsQueueConnectionFactory        factory,
    tibjmsQueueConnection*              connection,
    const char *                        username,
    const char *                        password);


extern tibjms_status
tibjmsXAConnectionFactory_CreateXAConnection(
    tibjmsXAConnectionFactory           factory,
    tibjmsConnection*                   connection,
    const char *                        username,
    const char *                        password);


extern tibjms_status
tibjmsXATopicConnectionFactory_CreateXAConnection(
    tibjmsXATopicConnectionFactory      factory,
    tibjmsTopicConnection*              connection,
    const char *                        username,
    const char *                        password);


extern tibjms_status
tibjmsXAQueueConnectionFactory_CreateXAConnection(
    tibjmsXAQueueConnectionFactory      factory,
    tibjmsQueueConnection*              connection,
    const char *                        username,
    const char *                        password);

extern tibjms_status
tibjmsConnectionFactory_CreateConnectionSSL(
    tibjmsConnectionFactory             factory,
    tibjmsConnection*                   connection,
    const char *                        username,
    const char *                        password,
    tibjmsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibjms_status
tibjmsTopicConnectionFactory_CreateConnectionSSL(
    tibjmsTopicConnectionFactory        factory,
    tibjmsTopicConnection*              connection,
    const char *                        username,
    const char *                        password,
    tibjmsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibjms_status
tibjmsQueueConnectionFactory_CreateConnectionSSL(
    tibjmsQueueConnectionFactory        factory,
    tibjmsQueueConnection*              connection,
    const char *                        username,
    const char *                        password,
    tibjmsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibjms_status
tibjmsXAConnectionFactory_CreateXAConnectionSSL(
    tibjmsXAConnectionFactory           factory,
    tibjmsConnection*                   connection,
    const char *                        username,
    const char *                        password,
    tibjmsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibjms_status
tibjmsXATopicConnectionFactory_CreateXAConnectionSSL(
    tibjmsXATopicConnectionFactory      factory,
    tibjmsTopicConnection*              connection,
    const char *                        username,
    const char *                        password,
    tibjmsSSLParams                     SSLparams,
    const char *                        pk_password);


extern tibjms_status
tibjmsXAQueueConnectionFactory_CreateXAConnectionSSL(
    tibjmsXAQueueConnectionFactory      factory,
    tibjmsQueueConnection*              connection,
    const char *                        username,
    const char *                        password,
    tibjmsSSLParams                     SSLparams,
    const char *                        pk_password);


/*************************************************************************/
/* public types used by the API                                          */
/*************************************************************************/

typedef struct __tibjmsLookupContext*       tibjmsLookupContext;


/*************************************************************************/
/* public API                                                            */
/*************************************************************************/

/* create a tibjmsd lookup context */
extern tibjms_status
tibjmsLookupContext_Create(
    tibjmsLookupContext*    context,
    const char*             brokerURL,
    const char*             username,
    const char*             password);


extern tibjms_status
tibjmsLookupContext_CreateSSL(
    tibjmsLookupContext*    context,
    const char*             brokerURL,
    const char*             username,
    const char*             password,
    tibjmsSSLParams         SSLparams,
    const char*             pk_password);

extern tibjms_status
tibjmsLookupContext_Destroy(
    tibjmsLookupContext     context);
    

/* generic lookup any object type */
extern tibjms_status
tibjmsLookupContext_Lookup(
    tibjmsLookupContext         context,
    const char*                 name,
    void**                      object);

/* lookup destination */
extern tibjms_status
tibjmsLookupContext_LookupDestination(
    tibjmsLookupContext         context,
    const char*                 name,
    tibjmsDestination*          destination);


/* lookup connection factory */
extern tibjms_status
tibjmsLookupContext_LookupConnectionFactory(
    tibjmsLookupContext         context,
    const char*                 name,
    tibjmsConnectionFactory*    factory);


extern const char*
tibjms_Version(void);

extern tibjms_int
tibjms_GetSocketReceiveBufferSize(void);

extern tibjms_status
tibjms_SetSocketReceiveBufferSize(
    tibjms_int kilobytes);

extern tibjms_int
tibjms_GetSocketSendBufferSize(void);

extern tibjms_status
tibjms_SetSocketSendBufferSize(
    tibjms_int kilobytes);

extern tibjms_int
tibjms_GetConnectAttemptCount(void);

extern tibjms_status
tibjms_SetConnectAttemptCount(
    tibjms_int count);

extern tibjms_int
tibjms_GetConnectAttemptDelay(void);

extern tibjms_status
tibjms_SetConnectAttemptDelay(
    tibjms_int delay);

extern tibjms_int
tibjms_GetReconnectAttemptCount(void);

extern tibjms_status
tibjms_SetReconnectAttemptCount(
    tibjms_int count);

extern tibjms_int
tibjms_GetReconnectAttemptDelay(void);

extern tibjms_status
tibjms_SetReconnectAttemptDelay(
    tibjms_int delay);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibjms_h */
