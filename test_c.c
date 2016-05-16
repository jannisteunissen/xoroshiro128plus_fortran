#include <stdio.h>
#include <stdint.h>
#include "xoroshiro128plus.c"

int main(void) {
  s[0] = -1337;
  s[1] = 9812374;

  for(int i = 0; i < 1000*1000*1000; i++) {
    next();
  }

  jump();

  printf("%ld\n", next());
}
