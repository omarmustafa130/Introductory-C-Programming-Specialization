#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int anArray[] = {5,16,33,99};
  int * p = anArray; //p->5
  printf("*p = %d\n", *p); //"p = 5"
  p++; //p->16
  printf("Now *p = %d\n", *p); //"Now *p = 16'
  int * q = &anArray[3];  // q->99
  int ** x = &q; //x->q->99
  **x = 12; //x->q->12  {5,16,33,12}
  *x = p;   // x->p->16
  **x = 42; //x->p->42    {5,42,33,12}
  q[1] = 9; //anArray[] = {5,42,9,12}
  for (int i =0; i < 4; i++){
    printf("anArray[%d] = %d\n",i, anArray[i]);
  }
  return EXIT_SUCCESS;
}
//anArray[0] = 5
//anArray[1] = 42
//anArray[2] = 9
//anArray[3] = 12
