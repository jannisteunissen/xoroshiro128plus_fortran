#include <stdio.h>
#include <stdint.h>
#include "xoroshiro128plus.c"

int main(void) {
  s[0] = -1337;
  s[1] = 9812374;

  for(int i = 0; i < 10; i++) {
    printf("%ld\n", next());
  }

  jump();

  for(int i = 0; i < 10; i++) {
    printf("%ld\n", next());
  }
}
