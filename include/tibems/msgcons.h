/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: msgcons.h,v $
 * $Revision: 1.8 $
 * $Date: 2004/01/21 01:44:46 $
 */

#ifndef _INCLUDED_tibemsmsgcons_h
#define _INCLUDED_tibemsmsgcons_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef void
(*tibemsMsgCallback) (
    tibemsMsgConsumer   msgConsumer,
    tibemsMsg           msg,
    void*               closure);

extern tibems_status
tibemsMsgConsumer_Close(
    tibemsMsgConsumer           msgConsumer);

extern tibems_status
tibemsMsgConsumer_GetMsgSelector(
    tibemsMsgConsumer           msgConsumer,
    const char**                selectorPtr);

extern tibems_status
tibemsMsgConsumer_Receive(
    tibemsMsgConsumer           msgConsumer,
    tibemsMsg*                  msg);

extern tibems_status
tibemsMsgConsumer_ReceiveTimeout(
    tibemsMsgConsumer           msgConsumer,
    tibemsMsg*                  msg,
    tibems_long                 timeout);

extern tibems_status
tibemsMsgConsumer_ReceiveNoWait(
    tibemsMsgConsumer           msgConsumer,
    tibemsMsg*                  msg);

extern tibems_status
tibemsMsgConsumer_SetMsgListener(
    tibemsMsgConsumer           msgConsumer,
    tibemsMsgCallback           callback,
    void*                       closure);

extern tibems_status
tibemsMsgConsumer_GetMsgListener(
    tibemsMsgConsumer           msgConsumer,
    tibemsMsgCallback*          callbackPtr,
    void**                      closure);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsmsgcons_h */
