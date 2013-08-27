AC_DEFUN([TIBCO_LIB_CHK], [
  AC_CHECK_SIZEOF(long int, 4)
  AC_MSG_CHECKING([if we're on a 64-bit platform])
  if test "$ac_cv_sizeof_long_int" = "4" ; then
    AC_MSG_RESULT([no])
    TIBCO_LIBNAME=tibems
  else
    AC_MSG_RESULT([yes])
    TIBCO_LIBNAME=tibems64
  fi
  str="$TIBCO_DIR/$1/lib$TIBCO_LIBNAME.*"
  for j in `echo $str`; do
    if test -r $j; then
      TIBCO_LIB_DIR=$TIBCO_DIR/$1
      break 2
    fi
  done
])

PHP_ARG_WITH(tibco, for Tibco JMS support,
[  --with-tibco[=DIR]      Include Tibco JMS support. DIR is the Tibco JMS C Client base directory])

if test "$PHP_TIBCO" != "no"; then
  AC_DEFINE(HAVE_TIBCO, 1, [Whether you have Tibco JMS])

  TIBCO_DIR=
  TIBCO_INC_DIR=

  for i in $PHP_TIBCO /usr/local /usr; do
    if test -r $i/include/tibems/tibems.h; then
      TIBCO_DIR=$i
      TIBCO_INC_DIR=$i/include/tibems
      break
    elif test -r $i/include/tibems.h; then
      TIBCO_DIR=$i
      TIBCO_INC_DIR=$i/include
      break
    fi
  done

  if test -z "$TIBCO_DIR"; then
    AC_MSG_ERROR([Cannot find Tibco JMS header files under $PHP_TIBCO. Note that the Tibco JMS client c library is not bundled with php!])
  fi

  TIBCO_LIBNAME=tibems

  for i in $PHP_LIBDIR $PHP_LIBDIR/tibems; do
    TIBCO_LIB_CHK($i)
  done

  if test -z "$TIBCO_LIB_DIR"; then
    AC_MSG_ERROR([Cannot find lib$TIBCO_LIBNAME under $TIBCO_DIR. Note that the Tibco JMS client c library is not bundled with php!])
  fi


  PHP_ADD_LIBRARY_WITH_PATH($TIBCO_LIBNAME, $TIBCO_LIB_DIR, TIBCO_SHARED_LIBADD)
  PHP_ADD_INCLUDE($TIBCO_INC_DIR)
  PHP_NEW_EXTENSION(tibco, tibco.c, $ext_shared)

  TIBCO_MODULE_TYPE=external
  TIBCO_LIBS="-L$TIBCO_LIB_DIR -l$TIBCO_LIBNAME $TIBCO_LIBS"
  TIBCO_INCLUDE=-I$TIBCO_INC_DIR
 
  PHP_SUBST(TIBCO_SHARED_LIBADD)
  PHP_SUBST_OLD(TIBCO_MODULE_TYPE)
  PHP_SUBST_OLD(TIBCO_LIBS)
  PHP_SUBST_OLD(TIBCO_INCLUDE)

fi
