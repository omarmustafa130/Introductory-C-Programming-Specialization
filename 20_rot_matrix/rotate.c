#include <stdio.h>
#include <stdlib.h>
void rotate(char matrix[10][10])
{
  char matrix_temp;

  //transpose
  for (int i = 0; i<10; i++)
  {
    for (int k =i; k<10; k++)
    {
      matrix_temp = matrix[k][i];
      matrix[k][i] = matrix[i][k];
      matrix[i][k]= matrix_temp;
    }
  }

  //reverse
  for(int j =0; j<10; j++)
  {
    for(int n=0; n<5; n++)
    {
      matrix_temp = matrix[j][n];
      matrix[j][n] = matrix[j][9-n];
      matrix[j][9-n] = matrix_temp;
    }
  }
}
