#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char u8;

void rotate(char matrix[10][10]);

int chack_matrix(FILE* f);

void printMatrix(char matrix [10][10]);

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: rotateMatrix InputFilename");
        return EXIT_FAILURE;
    }

    FILE* f = fopen(argv[1], "r");

    if (f == NULL)
    {
        perror("could not open file!");
        return EXIT_FAILURE;
    }

    if(chack_matrix(f) == 0)
    {
        printf("Matrix is not 10 by 10");
        return EXIT_FAILURE;
    }

    if(fclose(f) != 0)
    {
        perror("Error closing the file");
        return EXIT_FAILURE;
    }

    
    f = fopen(argv[1], "r");
    
    if (f == NULL)
    {
        perror("could not open file!");
        return EXIT_FAILURE;
    }
    char matrix [10][10];
    char c =0;
    for(u8 i = 0; i<10; i++)
    {
        for(u8 j=0; j<11; j++)
        {
            if ((c=fgetc(f)) != '\n')
            {
                matrix[i][j] = c;
            }
        }
    }
    if(fclose(f) != 0)
    {
        perror("Error closing the file");
        return EXIT_FAILURE;
    }
    rotate(matrix);
    printMatrix(matrix);

    return EXIT_SUCCESS;
}



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
int chack_matrix(FILE* f)
{
    int row_num = 0; 
    char c;
    while ((c=fgetc(f)) != EOF)
    {
        for (int i =0;i<10;i++)
        {   
            if (c == '\n') {
                fprintf(stderr,"less than 10 char in a line");
                return 0;
            }
            c = fgetc(f);
            
        }
        if (c != '\n')
        {
            fprintf(stderr,"more than 10 char in a line");
            return 0;
        }
        row_num++;
    } 

    if (row_num==10)
        return 1;
    else
    {
        fprintf(stderr,"do not have 10 row");
        return 0;
    }
}


void printMatrix(char matrix [10][10])
{
    for (u8 r = 0; r<10; r++)
    {
        for(u8 c = 0; c<10; c++)
        {
            printf("%c",matrix[r][c]);
        }
        printf("\n");
    }
}
