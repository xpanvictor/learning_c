
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  printf("Hello world, (pid: %d)\n", (int) getpid());
  int rc = fork();

  printf("The date-time is %s-%s\n", __DATE__, __TIME__);

  if (rc < 0) {
    fprintf(stderr, "Couldn't fork this process");
    exit(1);
  } else if (rc == 0) { // Child process new one
    printf("Running child process %d\n", (int) getpid());
    // Using execvp
    char * proc_args[3];
    proc_args[0] = strdup("wc");
    proc_args[1] = strdup("unix_exec.c"); // Checking length of this program
    proc_args[2] = NULL; // marks end of the command
    execvp(proc_args[0], proc_args); // Uses the execvp variant of exec to run the command
    printf("This part doesn't run\n");
  } else { // parent process
    int rc_wait = wait(NULL);
    printf("Parent process (pid: %d) of (rc: %d; rc_wait: %d)\n", (int) getpid(), rc, rc_wait);
  }
}

