
#include <dlfcn.h>

int bar(int a, void *h) {
  dlclose(h);
  return a;
}
