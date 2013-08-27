/* ***********************IMPORTANT ***************************************
 *  Copyright (C) 2006 Lukas Prettenthaler <http://zyclonite.net>         *
 *  This program is free software; you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation; either version 2 of the License.        *
 *                                                                        *
 *                      ********************                              *
 *                                                                        *
 *  This program is distributed in the hope that it will be useful,       *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *  GNU Library General Public License for more details.                  *
 *                                                                        *
 *                      ********************                              *
 *                                                                        *
 * You are highly encouraged to send your changes to <rdx@wsn.at>         *
 * for possible incorporation into the main distribution.                 *
 * By sending these changes to <rdx@wsn.at>, it is assumed                *
 * that you are offering <rdx@wsn.at> the unlimited,                      *
 * non-exclusive right to reuse, modify, and relicense the code.          *
 **************************************************************************/
#ifndef PHP_TIBCO_H
#define PHP_TIBCO_H 1

#define PHP_TIBCO_VERSION "1.00"
#define PHP_TIBCO_EXTNAME "tibco"

PHP_MSHUTDOWN_FUNCTION(tibco);
PHP_MINFO_FUNCTION(tibco);

PHP_FUNCTION(tibco_version);
PHP_FUNCTION(tibco_sendmsg);
PHP_FUNCTION(tibco_recvmsg);
PHP_FUNCTION(tibco_connect);
PHP_FUNCTION(tibco_disconnect);

extern zend_module_entry tibco_module_entry;
#define phpext_tibco_ptr &tibco_module_entry

#endif
