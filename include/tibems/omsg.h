/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: omsg.h,v $
 * $Revision: 1.9 $
 * $Date: 2004/01/21 01:44:46 $
 */

#ifndef _INCLUDED_tibemsobjectmsg_h
#define _INCLUDED_tibemsobjectmsg_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern tibems_status
tibemsObjectMsg_Create(
    tibemsObjectMsg*    message);

extern tibems_status
tibemsObjectMsg_GetObjectBytes(
    tibemsObjectMsg     message,
    void**              bytes,
    tibems_uint*        byteSize);

extern tibems_status
tibemsObjectMsg_SetObjectBytes(
    tibemsObjectMsg     message,
    const void*         bytes,
    tibems_uint         byteSize);

#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsobjectmsg_h */
