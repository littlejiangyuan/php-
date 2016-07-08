//walu.c

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "zend_extensions.h"
#include "zend_exceptions.h"
#include "ext/standard/info.h"
#include "ext/standard/file.h"
#include "ext/standard/php_string.h"
#include "ext/date/php_date.h"
#include <stdlib.h>

#include "john.h"


static zend_function_entry john_functions[] = {
    PHP_FE(walu_hello,        NULL)
    { NULL, NULL, NULL }
};

ZEND_FUNCTION(walu_hello)
{
	ZVAL_LONG(return_value, 42);
}

//module entry
zend_module_entry john_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
     STANDARD_MODULE_HEADER,
#endif
    "john", //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
	john_functions, /* Functions */
    NULL, /* MINIT */
    NULL, /* MSHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    "2.1", //这个地方是我们扩展的版本
#endif
    STANDARD_MODULE_PROPERTIES
};
 
#ifdef COMPILE_DL_JOHN
ZEND_GET_MODULE(john)
#endif


