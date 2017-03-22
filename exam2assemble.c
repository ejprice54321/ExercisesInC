#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

unsigned short assemble (char a, char b){
  unsigned short x = a;
  printf("%d\n", a);
  printf("%d\n", b);
  x <<= 8;
  printf("%d\n", x);
  x = x | b;
  printf("%d\n", x);
  return x;
}

int main(){
  unsigned short x = assemble(1, 2);
  printf("%d\n", x);
  return 0;
}
