#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#define alphabet_start  97
#define most_frequent_letter 101

int break_cipher(unsigned char* freq_arr);

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: ./Breaker InputFileName\n");
    return EXIT_FAILURE;
  }

  FILE* f = fopen(argv[1], "r");
  if (f == NULL) {
    printf("No file\n");
    return EXIT_FAILURE;
  }
  
  int key = 0;
  unsigned char freq_arr [26]={0};
  char c=0;

  while((c=fgetc(f))!=EOF)
  {
    if(isalpha(c))
    {
      c=tolower(c);
      freq_arr[(c-alphabet_start)]+=1;
    }
  }
  key = break_cipher(freq_arr);
  if (fclose(f) != 0){
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
    }
  
  fprintf(stdout, "%d\n",key);
  return EXIT_SUCCESS;

}

int break_cipher(unsigned char freq_arr[])
{ 
  unsigned char max = 0;
  unsigned char max_index = 0;
  int key = 0;
  for (unsigned char i = 0; i < 26; i++)
  {
    if(freq_arr[i]>max)
    {
      max = freq_arr[i];
      max_index = i;
    }
  }
 
  key = (max_index + alphabet_start) - most_frequent_letter;
  if (key <0)
    key+=26;
  else 
    key%=26;
  
  assert(key>=0 && key < 26);
  return key;
}
