#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("Hello world from %ld\n", (long)getpid());
  return 0;
}

