/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: tibems.h,v $
 * $Revision: 1.3 $
 * $Date: 2005/09/07 18:05:01 $
 */

#ifndef _INCLUDED_tibems_h
#define _INCLUDED_tibems_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "types.h"
#include "status.h"
#include "dest.h"
#include "conn.h"
#include "tconn.h"
#include "qconn.h"
#include "tsess.h"
#include "qsess.h"
#include "msgreq.h"
#include "msgprod.h"
#include "pub.h"
#include "send.h"
#include "msgcons.h"
#include "sub.h"
#include "recv.h"
#include "msg.h"
#include "tmsg.h"
#include "bmsg.h"
#include "smsg.h"
#include "omsg.h"
#include "mmsg.h"
#include "qbrow.h"
#include "xares.h"
#include "cssl.h"
#include "clookup.h"
#include "proxy.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern const char*
tibems_Version(void);

extern tibems_int
tibems_GetSocketReceiveBufferSize(void);

extern tibems_status
tibems_SetSocketReceiveBufferSize(
    tibems_int kilobytes);

extern tibems_int
tibems_GetSocketSendBufferSize(void);

extern tibems_status
tibems_SetSocketSendBufferSize(
    tibems_int kilobytes);

extern tibems_int
tibems_GetConnectAttemptCount(void);

extern tibems_status
tibems_SetConnectAttemptCount(
    tibems_int count);

extern tibems_int
tibems_GetConnectAttemptDelay(void);

extern tibems_status
tibems_SetConnectAttemptDelay(
    tibems_int delay);

extern tibems_int
tibems_GetReconnectAttemptCount(void);

extern tibems_status
tibems_SetReconnectAttemptCount(
    tibems_int count);

extern tibems_int
tibems_GetReconnectAttemptDelay(void);

extern tibems_status
tibems_SetReconnectAttemptDelay(
    tibems_int delay);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibems_h */
