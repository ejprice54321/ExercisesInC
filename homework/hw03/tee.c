#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char opt = "w";
  char ch;

  while((ch = getopt(argc, argv, "a:")) != EOF)
  switch(ch){
    case 'a':
      opt = ch;
    default:
      FILE *file = fopen(argv[], "w");
  }
  if (argv[] == "")


}
