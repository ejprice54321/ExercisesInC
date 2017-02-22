#include <stdio.h>

int int_to_int(int k) {
  int bit_k = (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_int(k / 2)));
  int a = (bit_k & bit_k);
  int b = (~bit_k & ~bit_k);
  return (~a & ~b);
}

int main()
{
  int val = 12;

  printf("%i\n", int_to_int(val));
}
