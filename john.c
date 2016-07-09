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

ZEND_BEGIN_ARG_INFO(byref_compiletime_arginfo, 0)
	ZEND_ARG_INFO(1, 'a')
	ZEND_ARG_INFO(0, 'b')
	ZEND_ARG_ARRAY_INFO(0, 'c', 1)
ZEND_END_ARG_INFO()

//声明导出函数快
static zend_function_entry john_functions[] = {
    PHP_FE(para_ref,        NULL)
	PHP_FE(comp_ref,        byref_compiletime_arginfo)
    { NULL, NULL, NULL }
};

ZEND_FUNCTION(para_ref)
{

}

/*************chapter 2**************/
ZEND_FUNCTION(comp_ref)
{
	zval *a,*c;
	long b;

	//我们我接收的参数传给zval *a;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zla", &a, &b, &c) == FAILURE)
    {
		RETURN_NULL();
	}

	long tmp = 0;
	tmp = Z_LVAL_P(a) + b;
	Z_LVAL_P(a) = tmp;

	array_init(return_value);

	//zend_hash_copy( Z_ARRVAL_P(return_value), Z_ARRVAL_P(c), NULL, NULL, sizeof(zval *) );
	add_next_index_long(c, tmp );
	Z_ARRVAL_P(return_value) = Z_ARRVAL_P(c);

	return;
}


//填写模块信息
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


