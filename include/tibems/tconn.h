/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: tconn.h,v $
 * $Revision: 1.8 $
 * $Date: 2005/12/09 23:39:02 $
 */

#ifndef _INCLUDED_tibemstconn_h
#define _INCLUDED_tibemstconn_h

#include "conn.h"
#include "types.h"
#include "status.h"
#include "sess.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern tibems_status
tibemsTopicConnection_Create(
    tibemsTopicConnection*              topicConnection,
    const char*                         brokerURL,
    const char*                         clientId,
    const char*                         username,
    const char*                         password);

extern tibems_status
tibemsTopicConnection_CreateTopicSession(
    tibemsTopicConnection               topicConnection,
    tibemsTopicSession*                 topicSession,
    tibems_bool                         transacted,
    tibemsAcknowledgeMode               ackowledgeMode);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemstconn_h */
