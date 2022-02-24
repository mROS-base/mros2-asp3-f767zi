
#ifndef TECS_NO_GCC_EXTENSION_SUPPORT

/*
 * these extension can be eliminated also by spefcifying option
 * --no-gcc-extension-support for tecsgen.
 */
#ifdef __GNUC__

#ifndef __attribute__
#define __attribute__(x)
#endif

#ifndef __extension__
#define __extension__
#endif

#ifndef __builtin_va_list
#define __builtin_va_list va_list
#endif

#ifndef __asm__
#define __asm__(x)
#endif

#ifndef restrict
#define restrict
#endif

#endif /* ifdef __GNUC__ */
#endif /* TECS_NO_GCC_EXTENSION_SUPPORT */

/* va_list is not supported in C_parser.y.rb */
typedef struct { int dummy; } va_list;

#include "nucleo_f767zi.h"
