/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: msgreq.h,v $
 * $Revision: 1.5 $
 * $Date: 2004/01/21 01:44:46 $
 */

#ifndef _INCLUDED_tibemsmsgreq_h
#define _INCLUDED_tibemsmsgreq_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct __tibemsMsgRequestor
{
    tibemsSession               session;
    tibemsDestination           sendDest;
    tibemsDestination           receiveDest;
    tibemsMsgProducer           producer;
    tibemsMsgConsumer           consumer;

} _tibemsMsgRequestorRec, *_tibemsMsgRequestor;

extern tibems_status
tibemsQueueRequestor_Create(
    tibemsQueueSession          session,
    tibemsMsgRequestor*         msgRequestor,
    tibemsQueue                 queue);

extern tibems_status
tibemsTopicRequestor_Create(
    tibemsTopicSession          session,
    tibemsMsgRequestor*         msgRequestor,
    tibemsTopic                 topic);

extern tibems_status
tibemsMsgRequestor_Request(
    tibemsMsgRequestor          msgRequestor,
    tibemsMsg                   msgSent,
    tibemsMsg*                  msgReply);

extern tibems_status
tibemsMsgRequestor_Close(
    tibemsMsgRequestor          msgRequestor);


#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsmsgreq_h */
