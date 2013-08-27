/*
 * ================================================================= 
 * Copyright (c) 2001-2003 TIBCO Software Inc. 
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 * 
 * $RCSfile: tibemsUtilities.h,v $
 * $Revision: 1.2 $
 * $Date: 2004/05/11 16:38:43 $
 * =================================================================
 */

#ifndef _INCLUDED_tibemsUtilities_h
#define _INCLUDED_tibemsUtilities_h

#include <tibems/tibems.h>

extern void
sslUsage();

extern void
setSSLParams(
    tibemsSSLParams ssl_params,
    int argc, 
    char* argv[]);

extern void
ldapUsage();

extern tibems_status
setLookupParams(
    tibemsLookupParams lookup_params,
    int argc, 
    char* argv[]);

#endif /* _INCLUDED_tibemsUtilities_h */

