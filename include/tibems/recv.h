/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: recv.h,v $
 * $Revision: 1.6 $
 * $Date: 2004/01/21 01:44:46 $
 */

#ifndef _INCLUDED_tibemsqrecv_h
#define _INCLUDED_tibemsqrecv_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern tibems_status
tibemsQueueReceiver_GetQueue(
    tibemsQueueReceiver         queueReceiver,
    tibemsQueue*                queue);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsqrecv_h */
