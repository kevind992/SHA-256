// Kevin Delassus, 2019
// The secure hashing algorithm, 256 bit version
// https://ws680.nist.gov/publication/get_pdf.cfm?pub_id=919060

#include <stdio.h>
#include <stdint.h>

void sha256();

// See Sections 4.1.2 for definitions.
uint32_t sig_0(uint32_t x);
uint32_t sig_1(uint32_t x);

// See Sections 3.2 for definitions
uint32_t rotr(uint32_t n, uint32_t x);
uint32_t shr(uint32_t n, uint32_t x);

int main(int argc, char *argv[]){
  
  sha256();
  return 0;
}

void sha256(){

  // Message schedule (Section 6.2)
  uint32_t W[64];
  // Working variables (Section 6.2)
  uint32_t a, b, c, d, e, f, g, h;
  // The Hast value (section 6.2)
  uint32_t H[8];
  // Two temporary variables (Section 6.2)
  uint32_t T1, T2;

  // The hash value (Section 6.2)
  // The values come from Section 5.3.3.
  uint32_t H[8] = {
      0x6a09e667
    , 0xbb67ae85
    , 0x3c6ef372
    , 0xa54ff53a
    , 0x510e527f
    , 0x9b05688c
    , 0x1f83d9ab
    , 0x5be0cd19
  };

  // The current message block
  uint32_t M[16];

  // For looping
  int t;

  // From page 22, W[t] = M[t] from 0 <= t <= 15
  for (t = 0; t < 16; t++)
    W[t] = M[t]; 
  
  for (t = 16; t < 64; t++)
    sig_1(W[t-2]) + W[t-7] + sig_0(W[t-15]) + W[t-16];

  // Initialise a, b, c, d and e as per Step 2, Page 22. 
  a = H[0]; b = H[1]; c = H[2]; d = H[3]; 
  e = H[4]; f = H[5]; g = H[6]; h = H[7];

  // Step 3.
  for(t = 0; t < 64; t++){
    T1 = h + SIG_1(e) + Ch(e,f,g) + K[t] + W[t];
    T2 = SIG_0(a) + Maj(a,b,c);
    h = g;
    g = f;
    f = e;
    e = d + T1;
    d = c;
    c = b;
    b = a;
    a = T1 + T2; 
  }

  // Step 4.
  H[0] = a + H[0];
  H[1] = a + H[1];
  H[2] = c + H[2];
  H[3] = d + H[3];
  H[4] = e + H[4];
  H[5] = f + H[5];
  H[6] = g + H[6];
  H[7] = h + H[7];

}

uint32_t rotr(uint32_t n, uint32_t x){
  return (x >> n) | (x << (32 -n));
}
uint32_t shr(uint32_t n, uint32_t x){
  return (x >> n);
}
uint32_t sig_0(uint32_t x){
  // See Sections 3.2 and 4.1.2 for definitions.
  return (rotr(7, x) ^ rotr(18, x) ^ shr(3, x));
}
uint32_t sig_1(uint32_t x){
  return (rotr(17, x) ^ rotr(19, x) ^ shr(10, x));
}


