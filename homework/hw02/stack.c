/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 //global

int *foo() {
  // creates an array, prints it's location,
  // fills each array value with 42
  // returns array
    int i;
    int array[SIZE];

    printf("%p\n", array);
    printf("%lu\n", sizeof(array));

    for (i=0; i<SIZE; i++) {
      	array[i] = 42;
    }
    return array;
}

void bar() {
  // creates array, prints the location
  // fills each array value with its array location
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
      	array[i] = i;
    }
}

int main()
{
  // calls foo(), which returns an the location of an array
  // calls bar()
  // fills the array
    int i;
    // int *array = foo();
    // printf("%lu\n", sizeof(array));
    //
    // bar();
    //
    // for (i=0; i<SIZE; i++) {
    //     printf("%d\n", array[i]);
    // }

    int a[10];
    for (i=0; i<10; i++) {
        printf("%d\n", a[i]);
        a[i] = 0;
    }
    int *p;
    p=a; /*legal*/
    for (i=0; i<10; i++) {
        printf("%d\n", p[i]);
    }

    return 0;
}
