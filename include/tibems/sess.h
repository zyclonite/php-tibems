/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: sess.h,v $
 * $Revision: 1.11 $
 * $Date: 2004/12/21 00:21:06 $
 */

#ifndef _INCLUDED_tibemssess_h
#define _INCLUDED_tibemssess_h

#include "types.h"
#include "status.h"
#include "msgprod.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* Multithreaded access OK for close */
extern tibems_status
tibemsSession_Close(
    tibemsSession               session);

extern tibems_status
tibemsSession_Commit(
    tibemsSession               session);

extern tibems_status
tibemsSession_CreateConsumer(
    tibemsSession               session,
    tibemsMsgConsumer*          consumer,
    tibemsDestination           destination,
    const char*                 optionalSelector,
    tibems_bool                 noLocal);

extern tibems_status
tibemsSession_CreateDurableSubscriber(
    tibemsSession               session,
    tibemsTopicSubscriber*      topicSubscriber,
    tibemsTopic                 topic,
    const char*                 subscriberName,
    const char*                 optionalSelector,
    tibems_bool                 noLocal);

extern tibems_status
tibemsSession_CreateBrowser(
    tibemsSession               session,
    tibemsQueueBrowser*         browser,
    tibemsQueue                 queue,
    const char*                 optionalSelector);

extern tibems_status
tibemsSession_CreateProducer(
    tibemsSession               session,
    tibemsMsgProducer*          producer,
    tibemsDestination           destination);

extern tibems_status
tibemsSession_CreateAsyncProducer(
    tibemsSession               session,
    tibemsMsgProducer*          producer,
    tibemsDestination           destination, 
    tibemsSendCompleteCallback  sendComplete,
    void*                       sendCompleteClosure,
    tibemsSendFailedCallback    sendFailed,
    void*                       sendFailedClosure,
    tibems_int                  sendWindow);

extern tibems_status
tibemsSession_CreateBytesMessage(
    tibemsSession               session,
    tibemsBytesMsg*             bytesMsg);

extern tibems_status
tibemsSession_CreateMapMessage(
    tibemsSession               session,
    tibemsMapMsg*               mapMsg);

extern tibems_status
tibemsSession_CreateMessage(
    tibemsSession               session,
    tibemsMsg*                  msg);

extern tibems_status
tibemsSession_CreateStreamMessage(
    tibemsSession               session,
    tibemsStreamMsg*            streamMsg);

extern tibems_status
tibemsSession_CreateTextMessage(
    tibemsSession               session,
    tibemsTextMsg*              textMsg);

extern tibems_status
tibemsSession_CreateTextMessageEx(
    tibemsSession               session,
    tibemsTextMsg*              textMsg,
    const char*                 textString);

extern tibems_status
tibemsSession_GetTransacted(
    tibemsSession               session,
    tibems_bool*                isTransacted);

extern tibems_status
tibemsSession_GetAcknowledgeMode(
    tibemsSession               session,
    tibemsAcknowledgeMode*      acknowledgeMode);

extern tibems_status
tibemsSession_Recover(
    tibemsSession               session);

extern tibems_status
tibemsSession_Rollback(
    tibemsSession               session);

extern tibems_status
tibemsSession_Unsubscribe(
    tibemsSession               session,
    const char*                 subscriberName);

extern tibems_status
tibemsSession_CreateTemporaryTopic(
    tibemsSession               session,
    tibemsTemporaryTopic*       tmpTopic);

extern tibems_status
tibemsSession_DeleteTemporaryTopic(
    tibemsSession               session,
    tibemsTemporaryTopic        tmpTopic);

extern tibems_status
tibemsSession_CreateTemporaryQueue(
    tibemsSession               session,
    tibemsTemporaryQueue*       tmpQueue);

extern tibems_status
tibemsSession_DeleteTemporaryQueue(
    tibemsSession               session,
    tibemsTemporaryQueue        tmpQueue);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemssess_h */
