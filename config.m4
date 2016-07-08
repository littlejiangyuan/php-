PHP_ARG_ENABLE(john,
    [Whether to enable the "john" extension],
    [  enable-john        Enable "john" extension support])

if test $PHP_JOHN != "no"; then PHP_SUBST(JOHN_SHARED_LIBADD)
    PHP_NEW_EXTENSION(john, john.c, $ext_shared)
fi
