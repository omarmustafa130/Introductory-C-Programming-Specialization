#include <stdio.h>
#include <stdlib.h>

int f(int ** r, int ** s) { //r->p->80 , s->q->12
  int temp = ** r;  //temp = 80
  int temp2 = **s;  // temp2 = 12
  int * z = *r;     // z->80
  *r = *s;          // r->q->12
  *s = z;           // s->z->80
  printf("**r = %d\n",**r); //**r = 12
  printf("**s = %d\n",**s); //**s = 80
  *z += 3;                  //z->83
  **s -= 8;                 //s->z->75
  **r -= 19;                //r->q->-7
  return temp + temp2;      //92
}

int main(void) {
  int a = 80;
  int b = 12;
  int * p = &a;   //p->80
  int * q = &b;   //q->12
  int x = f(&p, &q);// 92
  printf("x = %d\n", x); //x=92
  printf("*p = %d\n", *p); //*p = -7
  printf("*q = %d\n", *q); //*q = 75
  printf("a = %d\n", a);   //a = 75
  printf("b = %d\n", b);  //b = -7
  return EXIT_SUCCESS;
}
