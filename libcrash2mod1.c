
#include <dlfcn.h>

int
main()
{
  void *h = dlopen("$ORIGIN/libcrash2mod1.so", RTLD_LAZY);
  int (*fp) (void) = dlsym (h, "foo");
  return fp ();
}
-bash-4.1$ ^C
-bash-4.1$ ls
crash1-13    crash1-7   crash2.c  libcrash2mod1.c  own-sect.S  own.py  u.cc
crash1-1989  crash1.cc  imp.c     libcrash2mod2.c  own.cc      pop.cc  vec.cc
-bash-4.1$ cat libcrash2mod1.c
#include <dlfcn.h>

int foo(void) {
  void *h = dlopen("$ORIGIN/libcrash2mod2.so", RTLD_LAZY);
  int (*fp) (int, void *) = dlsym(h, "bar");
  //return fp(1, fp) + fp(2, fp);
  return fp(1, h) + fp(2, h);
}
