#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>

int global=10; //global variable stored in data segment ;
int main()
{
    int stack=10,i; //local variable , stored in stack segment ;
    char *buf;
    buf=(char *)malloc(20);//dynamically allocated variable, stored in heap;
    buf="PARENT";
    i=fork();
    if(i==0)//child process
    {
        global+=10;
        stack+=10;
        buf="CHILD";
    }
    printf("\n stack=%d,global=%d,buf=%s\n ",stack,global,buf);
    return 0;
}
