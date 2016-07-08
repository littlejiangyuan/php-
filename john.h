//john.h
#ifndef JOHN_H
#define JOHN_H
 
//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
//加载php头文件
#include "php.h"
#define phpext_john_ptr &john_module_entry
extern zend_module_entry john_module_entry;
 
#endif

//声明函数
PHP_FUNCTION(walu_hello);
