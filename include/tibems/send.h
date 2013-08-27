/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: send.h,v $
 * $Revision: 1.9 $
 * $Date: 2004/01/21 01:44:46 $
 */

#ifndef _INCLUDED_tibemsqsend_h
#define _INCLUDED_tibemsqsend_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern tibems_status
tibemsQueueSender_GetQueue(
    tibemsQueueSender           queueSender,
    tibemsQueue*                queue);

extern tibems_status
tibemsQueueSender_Send(
    tibemsQueueSender           queueSender,
    tibemsMsg                   msg);

extern tibems_status
tibemsQueueSender_SendEx(
    tibemsQueueSender           queueSender,
    tibemsMsg                   msg,
    tibems_int                  deliveryMode,
    tibems_int                  priority,
    tibems_long                 timeToLive);

extern tibems_status
tibemsQueueSender_SendToQueue(
    tibemsQueueSender           queueSender,
    tibemsQueue                 queue,
    tibemsMsg                   msg);

extern tibems_status
tibemsQueueSender_SendToQueueEx(
    tibemsQueueSender           queueSender,
    tibemsQueue                 queue,
    tibemsMsg                   msg,
    tibemsDeliveryMode          deliveryMode,
    tibems_int                  priority,
    tibems_long                 timeToLive);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsqsend_h */
