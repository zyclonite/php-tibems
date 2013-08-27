/*
 * Copyright (c) 2003 TIBCO Software Inc.
 * All Rights Reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 *
 * $RCSfile: tibiconv.h,v $
 * $Revision: 1.17 $
 * $Date: 2003/03/19 17:54:12 $
 */

#ifndef _INCLUDED_tibiconv_h
#define _INCLUDED_tibiconv_h

#include "tibiconv_encodings.h"

typedef unsigned short tibjms_UChar;

#if defined(__cplusplus)
extern "C" {
#endif

/*===========================================================================*/
/* Unicode character                                                         */
/*===========================================================================*/

typedef unsigned short tibiconv_UChar;
#define U_SIZEOF_UCHAR 2

typedef enum
{
    TIBICONV_TRUE		= (1==1),
    TIBICONV_FALSE		= (1==0)
    
} tibiconv_bool;

typedef enum
{
    TIBICONV_OK                 	= 0,
    TIBICONV_FAIL			= 1,
    
    TIBICONV_ILLEGAL_ARGUMENT_ERROR  =  101,       /* Start of codes indicating failure */
    TIBICONV_MISSING_RESOURCE_ERROR  =  102,
    TIBICONV_INVALID_FORMAT_ERROR    =  103,
    TIBICONV_FILE_ACCESS_ERROR       =  104,
    TIBICONV_INTERNAL_PROGRAM_ERROR  =  105,       /* Indicates a bug in the library code */
    TIBICONV_MESSAGE_PARSE_ERROR     =  106,
    TIBICONV_MEMORY_ALLOCATION_ERROR =  107,       /* Memory allocation error */
    TIBICONV_INDEX_OUTOFBOUNDS_ERROR =  108,
    TIBICONV_PARSE_ERROR             =  109,       /* Equivalent to Java ParseException */
    TIBICONV_INVALID_CHAR_FOUND      =  110,       /* In the Character conversion routines: 
						      Invalid character or sequence was encountered */
    TIBICONV_TRUNCATED_CHAR_FOUND    =  111,       /* In the Character conversion routines:
						      More bytes are required to complete the conversion
						      successfully */
    TIBICONV_ILLEGAL_CHAR_FOUND      =  112,       /* In codeset conversion:
						      a sequence that does NOT belong in the codepage
						      has been encountered */
    TIBICONV_INVALID_TABLE_FORMAT    =  113,       /* Conversion table file found10, but corrupted */
    TIBICONV_INVALID_TABLE_FILE      =  114,       /* Conversion table file not found */
    TIBICONV_BUFFER_OVERFLOW_ERROR   =  115,       /* A result would not fit in the supplied buffer */
    TIBICONV_UNSUPPORTED_ERROR       =  116,       /* Requested operation not supported in current context */
    
    TIBICONV_NO_DEFAULT_ENCODING     = 1000,
    TIBICONV_UNKNOWN_ENCODING        = 1001,
    TIBICONV_UNKNOWN_ERROR	     = 9999,

    TIBICONV_ERROR_LIMIT

} tibiconv_status;


extern tibiconv_bool
tibiconv_IsBigEndian(void);

extern tibiconv_bool
tibiconv_IsLittleEndian(void);

extern tibiconv_status
tibiconv_GetDefaultEncoding( const char** defaultEncoding );

extern tibiconv_status
tibiconv_SetDefaultEncoding( const char* defaultEncoding );

const char *
tibiconv_GetPlatformEncoding( void );

extern tibiconv_status
tibiconv_ConvertToUnicode(
    const char*         fromEncoding,
    char*	        pTarget,
    unsigned int        targetSize,
    const char*         pSource,
    unsigned int        sourceSize,
    unsigned int*       numValidBytes);

extern tibiconv_status
tibiconv_ConvertFromUnicode(
    const char*         toEncoding,
    char* 	        pTarget,
    unsigned int        targetSize,
    const char*         pSource,
    unsigned int        sourceSize,
    unsigned int*       numValidBytes);
    
extern tibiconv_status
tibiconv_LocalToUTF8(
    const char*	        pLocalString,
    char*               pUTF8,
    unsigned int        size);


extern tibiconv_status
tibiconv_UTF8ToLocal(
    const char*         pUTF8,
    char*               pLocalString,
    unsigned int        size);
    
    
extern tibiconv_status
tibiconv_ToUpper(
    char* 	        pTarget,
    const char*         pSource,
    unsigned int        sourceSize);

extern tibiconv_status
tibiconv_ToLower(
    char* 	        pTarget,
    const char*         pSource,
    unsigned int        sourceSize);


extern tibiconv_status
tibiconv_ToUpperUTF8(
    char* 	        pTarget,
    unsigned int        targetSize,
    const char*         pSource);

extern tibiconv_status
tibiconv_ToLowerUTF8(
    char* 	        pTarget,
    unsigned int        targetSize,
    const char*         pSource);

    
const char * 
tibiconv_GetStatusString (tibiconv_status status);


#ifdef  __cplusplus
}
#endif

#endif	/* _INCLUDED_tibiconv_h */
