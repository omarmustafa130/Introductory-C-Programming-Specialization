#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv)
{
  
  if (argc == 1)
  {
    char* line = NULL;
    size_t sz = 0;
    char ** new_arr = NULL;
    size_t idx = 0;
    while ((getline(&line, &sz, stdin))>=0)
    {
      new_arr = realloc(new_arr, (idx+1)*sizeof(*new_arr));
      new_arr[idx] = line;
      line = NULL;
      idx++;
    }
    free(line);
    sortData(new_arr, idx);

    for (size_t i = 0; i<idx; i++)
    {
      printf("%s", new_arr[i]);
      free(new_arr[i]);
    }
    free(new_arr);

    return EXIT_SUCCESS;
  }

  else if(argc >= 2)
  {
    FILE* f = NULL;
    for (int x = 1; x<argc; x++)
    {
      char* line = NULL;
      size_t sz = 0;
      char ** new_arr = NULL;
      size_t idx = 0;
      f=fopen(argv[x], "r");
      if (f ==NULL)
      {
        perror("could not open file");
        return EXIT_FAILURE;
      }

      while((getline(&line, &sz, f))>=0)
      {
        new_arr = realloc(new_arr, (idx+1) * sizeof(*new_arr));
        new_arr[idx] = line;
        line = NULL;
        idx++;
      }
      free(line);

      sortData(new_arr, idx);

      for (size_t i = 0; i<idx; i++)
      {
        printf("%s", new_arr[i]);
        free(new_arr[i]);
      }
      free(new_arr);

      if (fclose(f) != 0)
      {
        perror("Failed to close the file");
        return EXIT_FAILURE;
      }
    }


  }

  else 
  {
    fprintf(stderr, "Not enough arguments");
    return EXIT_FAILURE;
  }

}
