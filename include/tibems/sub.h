/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: sub.h,v $
 * $Revision: 1.8 $
 * $Date: 2004/01/21 01:44:47 $
 */

#ifndef _INCLUDED_tibemstsub_h
#define _INCLUDED_tibemstsub_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern tibems_status
tibemsTopicSubscriber_GetTopic(
    tibemsTopicSubscriber       topicSubscriber,
    tibemsTopic*                topic);

extern tibems_status
tibemsTopicSubscriber_GetNoLocal(
    tibemsTopicSubscriber       topicSubscriber,
    tibems_bool*                isNoLocal);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemstsub_h */
