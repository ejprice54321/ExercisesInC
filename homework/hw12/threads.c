#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void* do_stuff(void* param){
  long thread_num = (long)param;
  printf("Thread number %ld\n", thread_num);
  return (void*)(thread_num + 1);
}

int main(){
  pthread_t threads[20];
  long t;
  for (t=0; t<20; t++){
    pthread_create(&threads[t], NULL, do_stuff, (void*)t);
  }
  void* result;
  for (t=0; t<20; t++){
    pthread_join(threads[t], &result);
    printf("Thread %ld returned %ld\n", t, (long)result);
  }
  return 0;
}
