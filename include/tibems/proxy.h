/*
 * Copyright (c) 2001-2005 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: proxy.h,v $
 * $Revision: 1.4 $
 * $Date: 2005/12/09 23:39:02 $
 */

#ifndef _INCLUDED_proxy_h
#define _INCLUDED_proxy_h

#include "status.h"
#include "types.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct __tibemsConnectionFactory*       tibemsAnyConnectionFactory;
    
extern tibems_status
tibemsConnectionFactory_SetSSLProxy(
    tibemsAnyConnectionFactory          factory,
    const char*                         proxy_host,
    tibems_int                          proxy_port);

extern tibems_status
tibemsConnectionFactory_SetSSLProxyAuth(
    tibemsAnyConnectionFactory          factory,
    const char*                         proxy_user,
    const char*                         proxy_password);

extern tibems_status
tibemsConnectionFactory_GetSSLProxyHost(
    tibemsAnyConnectionFactory          factory,
    const char**                        proxy_host);

extern tibems_status
tibemsConnectionFactory_GetSSLProxyPort(
    tibemsAnyConnectionFactory          factory,
    tibems_int*                         proxy_port);

extern tibems_status
tibemsConnectionFactory_GetSSLProxyUser(
    tibemsAnyConnectionFactory          factory,
    const char**                        proxy_user);

extern tibems_status
tibemsConnectionFactory_GetSSLProxyPassword(
    tibemsAnyConnectionFactory          factory,
    const char**                        proxy_password);



#ifdef  __cplusplus
}
#endif

#endif /* _INCLUDED_proxy_h */
