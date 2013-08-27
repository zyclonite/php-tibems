/*
 * Copyright (c) 2001-2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: conn.h,v $
 * $Revision: 1.19 $
 * $Date: 2005/12/09 23:39:02 $
 */

#ifndef _INCLUDED_tibemsconn_h
#define _INCLUDED_tibemsconn_h

#include "types.h"
#include "status.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef void
(*tibemsExceptionCallback) (
    tibemsConnection    connection,
    tibems_status       status,
    void*               closure);

extern tibems_status
tibemsConnection_Create(
    tibemsConnection*           connection,
    const char*                 brokerURL,
    const char*                 clientId,
    const char*                 username,
    const char*                 password);

extern tibems_status
tibemsConnection_CreateSession(
    tibemsConnection            connection,
    tibemsSession*              session,
    tibems_bool                 transacted,
    tibemsAcknowledgeMode       acknowledgeMode);

extern tibems_status
tibemsConnection_Close(
    tibemsConnection            connection);

extern tibems_status
tibemsConnection_Start(
    tibemsConnection            connection);

extern tibems_status
tibemsConnection_Stop(
    tibemsConnection            connection);

extern tibems_status
tibemsConnection_GetClientId(
    tibemsConnection            connection,
    const char**                clientId);

extern tibems_status
tibemsConnection_SetClientId(
    tibemsConnection            connection,
    const char*                 clientId);

extern tibems_status
tibemsConnection_GetExceptionListener(
    tibemsConnection            connection,
    tibemsExceptionCallback*    listener,
    void**                      closure);

extern tibems_status
tibemsConnection_SetExceptionListener(
    tibemsConnection            connection,
    tibemsExceptionCallback     listenerCallback,
    const void*                 closure);

extern tibems_status
tibemsConnection_GetMetaData(
    tibemsConnection            connection,
    tibemsConnectionMetaData*   metaData);

extern tibems_status
tibemsConnection_GetActiveURL(
    tibemsConnection            connection,
    char**                      serverURL);

/*
 * This is the clean up routine before application exits.
 * It should only be used in Windows applications that
 * explicitly load and unload the EMS DLL. This function
 * must be called before unloading the EMS DLL.
 */

extern void
tibems_Close(void);

extern void
tibems_Sleep(tibems_long milliseconds);


#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_tibemsconn_h */
