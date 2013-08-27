/*
 * ================================================================= 
 * Copyright (c) 2001-2003 TIBCO Software Inc. 
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 * 
 * $RCSfile: tibemsUtilities.c,v $
 * $Revision: 1.3 $
 * $Date: 2004/05/11 17:03:42 $
 * =================================================================
 */

#include "tibemsUtilities.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*-----------------------------------------------------------------------
 * host name verifier
 *----------------------------------------------------------------------*/
static tibems_status
_verifyHostName(
    const char*     connected_hostname,
    const char*     expected_hostname,
    const char*     certificate_name,
    void*           closure)
{

    fprintf(stderr,"CUSTOM VERIFIER:\n"\
            "    connected: [%s]\n"\
            "    expected:  [%s]\n"\
            "    certCN:    [%s]\n",
        connected_hostname ? connected_hostname : "(null)",
        expected_hostname ? expected_hostname : "(null)",
        certificate_name ? certificate_name : "(null)");

    return TIBEMS_OK;
}

void
sslUsage()
{
    printf("\n");
    printf("   where ssl options are:\n");
    printf("\n");
    printf("   -ssl_trusted\n");
    printf("   -ssl_issuer\n");
    printf("   -ssl_identity\n");
    printf("   -ssl_key\n");
    printf("   -ssl_password\n");
    printf("   -ssl_hostname\n");
    printf("   -ssl_custom\n");
    printf("   -ssl_noverifyhost\n");
    printf("   -ssl_noverifyhostname\n");
    printf("   -ssl_trace\n");
    printf("   -ssl_debug_trace\n");
    exit(0);
}
/*-----------------------------------------------------------------------
 * setSSLParams
 *----------------------------------------------------------------------*/
void setSSLParams(
    tibemsSSLParams ssl_params,
    int argc, 
    char* argv[]) 
{
    tibems_status status = TIBEMS_OK;
    tibems_bool certs = TIBEMS_FALSE;
    int i=1;
    

    while(i < argc)
    {
        if (strcmp(argv[i],"-ssl_trusted")==0) 
        {
            if ((i+1) >= argc) sslUsage();

            status = tibemsSSLParams_AddTrustedCertFile(ssl_params,argv[i+1],
                                    TIBEMS_SSL_ENCODING_AUTO);
            if (status != TIBEMS_OK)
            {
                fprintf(stderr,"Error: invalid trusted parameter '%s'\n",
                    argv[i+1]);
                sslUsage();
            }
            certs = TIBEMS_TRUE;
            argv[i] = NULL;
            argv[i+1] = NULL;
            i += 2;
        }
        else
        if (strcmp(argv[i],"-ssl_issuer")==0) 
        {
            if ((i+1) >= argc) sslUsage();

            status = tibemsSSLParams_AddIssuerCertFile(ssl_params,argv[i+1],
                                TIBEMS_SSL_ENCODING_AUTO);
            if (status != TIBEMS_OK)
            {
                fprintf(stderr,"Error: invalid issuer parameter '%s'\n",
                    argv[i+1]);
                sslUsage();
            }
            argv[i] = NULL;
            argv[i+1] = NULL;
            i += 2;
        }
        else
        if (strcmp(argv[i],"-ssl_identity")==0) 
        {
            if ((i+1) >= argc) sslUsage();

            status = tibemsSSLParams_SetIdentityFile(ssl_params,argv[i+1],
                                    TIBEMS_SSL_ENCODING_AUTO);
            if (status != TIBEMS_OK)
            {
                fprintf(stderr,"Error: invalid identity parameter '%s'\n",
                    argv[i+1]);
                sslUsage();
            }
            argv[i] = NULL;
            argv[i+1] = NULL;
            i += 2;
        }
        else
        if (strcmp(argv[i],"-ssl_key")==0) 
        {
            if ((i+1) >= argc) sslUsage();

            status = tibemsSSLParams_SetPrivateKeyFile(ssl_params,argv[i+1],
                                    TIBEMS_SSL_ENCODING_AUTO);
            if (status != TIBEMS_OK)
            {
                fprintf(stderr,"Error: invalid private key parameter '%s'\n",
                    argv[i+1]);
                sslUsage();
            }
            argv[i] = NULL;
            argv[i+1] = NULL;
            i += 2;
        }
        else
        if (strcmp(argv[i],"-ssl_hostname")==0) 
        {
            if ((i+1) >= argc) sslUsage();

            tibemsSSLParams_SetExpectedHostName(ssl_params,argv[i+1]);
            argv[i] = NULL;
            argv[i+1] = NULL;
            i += 2;
        }
        else
        if (strcmp(argv[i],"-ssl_custom")==0) 
        {
            tibemsSSLParams_SetHostNameVerifier(ssl_params,_verifyHostName,NULL);
            argv[i] = NULL;
            i += 1;
        }
        else
        if (strcmp(argv[i],"-ssl_noverifyhost")==0) 
        {
            tibemsSSLParams_SetVerifyHost(ssl_params,TIBEMS_FALSE);
            argv[i] = NULL;
            i += 1;
        }
        else
        if (strcmp(argv[i],"-ssl_noverifyhostname")==0) 
        {
            tibemsSSLParams_SetVerifyHostName(ssl_params,TIBEMS_FALSE);
            argv[i] = NULL;
            i += 1;
        }
        else
        if (strcmp(argv[i],"-ssl_trace")==0) 
        {
            tibemsSSL_SetTrace(TIBEMS_TRUE);
            argv[i] = NULL;
            i += 1;
        }
        else
        if (strcmp(argv[i],"-ssl_debug_trace")==0) 
        {
            tibemsSSL_SetDebugTrace(TIBEMS_TRUE);
            argv[i] = NULL;
            i += 1;
        }
        else 
        {
            i += 1;
        }
    }

    if(!certs)
        tibemsSSLParams_SetVerifyHost(ssl_params,TIBEMS_FALSE);
}

