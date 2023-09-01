#include "core/core.h"
#include "dbg/print.h"

// main should never exit
EXTERN_C NO_RETURN void main()
{
  debug_printf("Hello Bob\n");
  while(1) {
  };
}