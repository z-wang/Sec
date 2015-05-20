
#include <dlfcn.h>

int
main()
{
  void *h = dlopen("$ORIGIN/libcrash2mod1.so", RTLD_LAZY);
  int (*fp) (void) = dlsym (h, "foo");
  return fp ();
}
