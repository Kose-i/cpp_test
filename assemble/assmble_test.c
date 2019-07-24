#include <stdio.h>

int main(void) {
  register int a=0;
  register int b=1;

  __asm__("movl  $0x0202, %ax;");

  a+=b;
  printf("%d\n",a);
}
