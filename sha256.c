#include <stdio.h>

int isprime(unsigned int test){
unsigned int i;
 
  for(i = 2; i < test; i++){
    if(test % i == 0){
      return 0;
    }
  }
    return 1;
}
  
int main(int argc, char *argv[]){
  unsigned int test = 365;
  
  if(isprime(test)){
    printf("%d is prime.\n",test);
  }else{
    printf("%d is not prime.\n",test);
  }
 return 0; 
}
