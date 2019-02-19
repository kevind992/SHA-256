#include <stdio.h>
#include <stdint.h>

void binprint(uint32_t x){
  int i;
  uint32_t one = 1;

  for (i = 0; i < 32; i++)
    if((one << (31 - i)) & x)
        printf("1");
    else
        printf("0");
}

uint32_t rotl(uint32_t x, int n) {
  return ((x << n) | (x >> (32 - n)));
}

uint32_t rotr(uint32_t x, int n){
  return ((x << (32 - n)) | (x >> n));
}

int main(int argc, char *argv[]){
  uint32_t a = 0x428a2f98;
  uint32_t b = 0x71374491;

  printf("hex a: %08x\n", a);
  printf("hex b: %08x\n", b);

  //printf("a: %08x\n", a);
  printf("   a: "); binprint(a); printf("\n");
  //printf("b: %08x\n", b);
  printf("   b: "); binprint(b); printf("\n");
  //printf(" &: %08x\n", (a&b));
  printf(" a&b: "); binprint(a&b); printf("\n");
  // printf(" |: %08x\n", (a|b));
  printf(" a|b: "); binprint(a|b); printf("\n");
  //printf(" ^: %08x\n", (a^b));
  printf(" a^b: "); binprint(a^b); printf("\n");
  //printf(" ~: %08x\n", (~a));
  printf("  ~a: "); binprint(~a); printf("\n");
  //printf("<<: %08x\n", (a<<1));
  printf("a<<1: "); binprint(a<<1); printf("\n");
  //printf(">>: %08x\n", (a>>1));
  printf("a>>1: "); binprint(a>>1); printf("\n");
  printf("a>>3: "); binprint(a>>3); printf("\n");
  printf("a<<3: "); binprint(a<<3); printf("\n");

  printf("rotl(a,3): "); binprint(rotl(a,3)); printf("\n");
  printf("rotr(a,3): "); binprint(rotr(a,3)); printf("\n");

  return 0;
}
