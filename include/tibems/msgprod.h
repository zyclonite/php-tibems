/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: msgprod.h,v $
 * $Revision: 1.10 $
 * $Date: 2004/12/21 00:21:06 $
 */

#ifndef _INCLUDED_tibemsmsgprod_h
#define _INCLUDED_tibemsmsgprod_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef void
(*tibemsSendCompleteCallback) (
    tibemsMsgProducer           msgProducer,
    tibemsMsg                   msg,
    void*                       closure);

typedef void
(*tibemsSendFailedCallback) (
    tibemsMsgProducer           msgProducer,
    tibemsMsg                   msg,
    tibems_status               status,
    void*                       closure);

extern tibems_status
tibemsMsgProducer_Close(
    tibemsMsgProducer           msgProducer);

extern tibems_status
tibemsMsgProducer_GetDeliveryMode(
    tibemsMsgProducer           msgProducer,
    tibems_int*                 deliveryMode);

extern tibems_status
tibemsMsgProducer_GetDisableMessageID(
    tibemsMsgProducer           msgProducer,
    tibems_bool*                doDisableMessageID);

extern tibems_status
tibemsMsgProducer_GetDisableMessageTimestamp(
    tibemsMsgProducer           msgProducer,
    tibems_bool*                doDisableMessageTimeStamp);

extern tibems_status
tibemsMsgProducer_GetPriority(
    tibemsMsgProducer           msgProducer,
    tibems_int*                 priority);

extern tibems_status
tibemsMsgProducer_GetTimeToLive(
    tibemsMsgProducer           msgProducer,
    tibems_long*                timeToLive);

extern tibems_status
tibemsMsgProducer_SetDeliveryMode(
    tibemsMsgProducer           msgProducer,
    tibems_int                  deliveryMode);

extern tibems_status
tibemsMsgProducer_SetDisableMessageID(
    tibemsMsgProducer           msgProducer,
    tibems_bool                 doDisableMessageID);

extern tibems_status
tibemsMsgProducer_SetDisableMessageTimestamp(
    tibemsMsgProducer           msgProducer,
    tibems_bool                 doDisableMessageTimeStamp);

extern tibems_status
tibemsMsgProducer_SetPriority(
    tibemsMsgProducer           msgProducer,
    tibems_int                  priority);

extern tibems_status
tibemsMsgProducer_SetTimeToLive(
    tibemsMsgProducer           msgProducer,
    tibems_long                 timeToLive);

extern tibems_status
tibemsMsgProducer_Send(
    tibemsMsgProducer           msgProducer,
    tibemsMsg                   msg);

extern tibems_status
tibemsMsgProducer_SendEx(
    tibemsMsgProducer           msgProducer,
    tibemsMsg                   msg,
    tibems_int                  deliveryMode,
    tibems_int                  priority,
    tibems_long                 timeToLive);

extern tibems_status
tibemsMsgProducer_SendToDestination(
    tibemsMsgProducer           msgProducer,
    tibemsDestination           destination,
    tibemsMsg                   msg);

extern tibems_status
tibemsMsgProducer_SendToDestinationEx(
    tibemsMsgProducer           msgProducer,
    tibemsDestination           destination,
    tibemsMsg                   msg,
    tibemsDeliveryMode          deliveryMode,
    tibems_int                  priority,
    tibems_long                 timeToLive);

extern tibems_status
tibemsMsgProducer_RecoverSend(
    tibemsMsgProducer producer);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsmsgprod_h */
