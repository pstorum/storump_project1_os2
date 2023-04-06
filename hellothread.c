#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>



void *run_thread(void* arg)
{
    char *thread_number = arg;
    for(int x = 0; x<=4; x++){
        printf("thread %s: %i\n", thread_number, x);
    }
    return NULL;
}

int main(void)
{
    printf("Launching Threads\n");
    pthread_t t1, t2;

    pthread_create(&t1, NULL, run_thread, "1");
    pthread_create(&t2, NULL, run_thread, "2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Threads complete!\n");
}