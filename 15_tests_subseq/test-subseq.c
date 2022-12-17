#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);

int main()
{
  
  int array_1[] = {1,2,3};
  size_t n_1 = 3;
  size_t ans = maxSeq(array_1,n_1);
  if(ans != 3) {return EXIT_FAILURE;}
  
  int array_2[] = {3,3,3};
  size_t n_2 = 3;
  ans = maxSeq(array_2,n_2);
  if(ans != 1) {return EXIT_FAILURE;}
  
  int array_3[] = {3};
  size_t n_3 = 1;
  ans = maxSeq(array_3,n_3);
  if(ans != 1) {return EXIT_FAILURE;}
  
  int array_4[] = {1,2,3, 2,1,9,8,7,8,2};
  size_t n_4 = 10;
  ans = maxSeq(array_4,n_4);
  if(ans != 3) {return EXIT_FAILURE;}

  int array_5[] = {};
  size_t n_5 = 0;
  ans = maxSeq(array_5,n_5);
  if(ans != 0) {return EXIT_FAILURE;}

  int array_6[] = {9,8,7,6,5};
  size_t n_6 = 5;
  ans = maxSeq(array_6,n_6);
  if(ans != 1) {return EXIT_FAILURE;}

  int array_7[] = {-9,-8,5,6,7};
  size_t n_7 = 5;
  ans = maxSeq(array_7,n_7);
  if(ans != 5) {return EXIT_FAILURE;}

  int array_8[] = {-9,-8,-7,5,6,7};
  size_t n_8 = 6;
  ans = maxSeq(array_8,n_8);
  if(ans != 6) {return EXIT_FAILURE;}

  int array_9[] = {1,0};
  size_t n_9 = 2;
  ans = maxSeq(array_9,n_9);
  if(ans != 1) {return EXIT_FAILURE;}

  int array_10[] = {0,1};
  size_t n_10 = 2;
  ans = maxSeq(array_10,n_10);
  if(ans != 2) {return EXIT_FAILURE;}

  int array_11[] = { 1, 2, 1, 3, 5, 7, 2, 4, 6, 9};
  size_t n_11 = 10;
  ans = maxSeq(array_11,n_11);
  if(ans != 4) {return EXIT_FAILURE;}

  int array_12[] = { 1, 3, 3, 3, 3, 3, 2, 4, 6, 9};
  size_t n_12 = 10;
  ans = maxSeq(array_12,n_12);
  if(ans != 4) {return EXIT_FAILURE;}

  int array_13[] = {-5,-3,-2,0,1,2,3,2,9};
  size_t n_13 = 9;
  ans = maxSeq(array_13,n_13);
  if(ans != 7) {return EXIT_FAILURE;}
  
  return EXIT_SUCCESS;
}
