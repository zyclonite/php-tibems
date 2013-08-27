/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: qconn.h,v $
 * $Revision: 1.9 $
 * $Date: 2005/12/09 23:39:02 $
 */

#ifndef _INCLUDED_tibemsqconn_h
#define _INCLUDED_tibemsqconn_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern tibems_status
tibemsQueueConnection_Create(
    tibemsQueueConnection*              queueConnection,
    const char*                         brokerURL,
    const char*                         clientId,
    const char*                         username,
    const char*                         password);

extern tibems_status
tibemsQueueConnection_CreateQueueSession(
    tibemsQueueConnection               queueConnection,
    tibemsQueueSession*                 queueSession,
    tibems_bool                         transacted,
    tibemsAcknowledgeMode               acknowledgeMode);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsqconn_h */
