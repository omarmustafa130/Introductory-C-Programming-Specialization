#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);
void run_check(unsigned x, unsigned y);
int main()
{
  
  if ( power(0,0) != 1) {return EXIT_FAILURE;}
  if ( power(0,1) != 0) {return EXIT_FAILURE;}
  if ( power(2,2) != 4) {return EXIT_FAILURE;}
  if ( power(0,10) != 0) {return EXIT_FAILURE;}
  if ( power(10,0) != 1) {return EXIT_FAILURE;}
  if ( power(1,0) != 1) {return EXIT_FAILURE;}
  if ( power(2,1) != 2) {return EXIT_FAILURE;}
  if ( power(1,2) != 1) {return EXIT_FAILURE;}
  if ( power(10,5) != 100000) {return EXIT_FAILURE;}
  if ( power(5,10) != 9765625) {return EXIT_FAILURE;}
  if ( power(2,31) != 2147483648) {return EXIT_FAILURE;}
  if ( power(5,5) != 3125) {return EXIT_FAILURE;}
  if ( power(2*3,2) != 36) {return EXIT_FAILURE;}
  return EXIT_SUCCESS;
}
