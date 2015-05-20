
#include <signal.h>
#include <stdio.h>

void h(int s)
{
  alarm(1);
}

int main() {
  struct sigaction sa;
  sa.sa_handler = h;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sigaction(SIGALRM, &sa, NULL);
  alarm(1);
  while (!feof(stdin)) {
    char buf[100];
    if (fgets(buf, sizeof(buf), stdin) == NULL)
      puts("** nothing");
    else
      printf("read \"%s\"\n", buf);
  }
  return 0;
}
