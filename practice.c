#include <stdio.h>
#include <stdlib.h>

int get_nonce(){
  int x = rand();
  const int y = x;
  return y;
}

int main(){
  // union{
  //   float f;
  //   unsigned int u;
  // }p;
  //
  // p.f = -13;
  // unsigned int sign = (p.u >> 31) & 1;
  // unsigned int exp = (p.u >> 23) & 0xff;
  //
  // unsigned int coef_mask = (1 << 23) - 1;
  // unsigned int coef = p.u & coef_mask;
  //
  // printf("%d\n", sign);
  // printf("%d\n", exp);
  // printf("%d\n", coef);
  //

  // int y = get_nonce();
  // printf("%d\n", y);
  // int x = get_nonce();
  // printf("%d\n", x);

  int y;
  printf("%lu\n", sizeof(y));

  return 0;


}
