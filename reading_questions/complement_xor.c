// #include <stdio.h>
//
// int int_to_int(int k) {
//   int bit_k = (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_int(k / 2)));
//   int a = (bit_k & bit_k);
//   int b = (~bit_k & ~bit_k);
//   return (~a & ~b);
// }
//
// int main()
// {
//   int val = 12;
//
//   printf("%i\n", int_to_int(val));
// }

#include <stdio.h>

int main() {
  char c = 12;
  char b = 255;
  int *p;
  printf("Output = %d\n", (c^b) + 1);

  char a[] = "somerandomstringoflowercaseletters";
  printf("%s\n", a);
  int i;

  for (i = 0; i < (sizeof(a) - 1); i++){
    a[i] = a[i]^32;
  }

  printf("%d\n", sizeof(c));
  printf("%d\n", sizeof(p));
  printf("%s\n", a);

  return 0;
}
