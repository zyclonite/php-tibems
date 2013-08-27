/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: tmsg.h,v $
 * $Revision: 1.7 $
 * $Date: 2004/01/21 01:44:47 $
 */

#ifndef _INCLUDED_tibemstextmsg_h
#define _INCLUDED_tibemstextmsg_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern tibems_status
tibemsTextMsg_Create(
    tibemsTextMsg*      message);

extern tibems_status
tibemsTextMsg_GetText(
    tibemsTextMsg       message,
    const char**        text);

extern tibems_status
tibemsTextMsg_SetText(
    tibemsTextMsg       message,
    const char*         text);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemstextmsg_h */
