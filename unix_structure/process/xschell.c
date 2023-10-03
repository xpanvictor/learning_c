#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


#define MAXLINE 4096

int sys_err(char *msg)
{
  fprintf(stdout, "Error: %s", msg);
  exit(1);
}

int main()
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%% "); // Use %% to print %
  while(fgets(buf, MAXLINE, stdin) != NULL) {
    if ((buf[strlen(buf) - 1]) == '\n')
      buf[strlen(buf) - 1] = 0;

    // fork a new process to run command
    if ((pid = fork()) < 0) {
      sys_err("Fork error");
    } else if (pid == 0) {
      // child
      execlp(buf, buf, (char *) 0);
      // err_ret("Couldn't execute: %s", buf);
      exit(127);
    }

    // parent
    if ((pid = waitpid(pid, &status, 0)) < 0)
      sys_err("waitpid error");

    printf("%% ");
  }

  exit(0);
}

