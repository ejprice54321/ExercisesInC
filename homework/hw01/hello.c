#include <stdio.h>
int main()
{
  /* optimization gets rid of variables not in use and
does some minor calculations because it can get rid of
x when it's only use is in y
  */
  int x=5; //when x is printed it shows up
  int y = x + 1; // when y is printed it shows up
  // when x is in y it also disappears
  printf("%i\n", y);
}
