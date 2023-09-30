#include <stdio.h>
#include <stdlib.h>
// #include "common.h"
// #include "common_threads.h"
#include "pthread.h"

volatile int counter = 0;
int loop;

void * worker(void *args) {
    int i;
    for (i = 0; i < loop; i++)
        counter++;
    return NULL;
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        // some error handling fts
        fprintf(stderr, "usage: thread <value>\n");
        exit(1);
    }
    loop = atoi(argv[1]);
    // create thread handlers
    pthread_t p1, p2;

    printf("Initial value %d\n", counter);

    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("After threads, final value: %d\n", counter);
    return 0;
}

