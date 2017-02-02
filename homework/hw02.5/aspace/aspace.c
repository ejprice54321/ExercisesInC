/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;


void localVal(int i)
{
  int local = i;
  printf ("Address of local is %p\n", &local);
}

int main ()
{
    int i;
    void *p = malloc(16);
    void *s = malloc(16);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of p is %p\n", p);
    printf ("Address of s is %p\n", s);

    for (i=0; i<20; i=i+1){
      localVal(i);
    }

    return 0;
}
