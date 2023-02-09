#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * splitKV(char * line)
{
  
  char * tempCh = strchr(line, '=');
  *tempCh = '\0';
  tempCh++;
  char * valueTempCh = strchr(tempCh, '\n');
  if(valueTempCh != NULL)
    *valueTempCh = '\0';
  kvpair_t* kvpair = malloc(sizeof(*kvpair));
  kvpair->key = line;
  kvpair->value = tempCh;
  
  return kvpair;
}

kvarray_t * readKVs(const char * fname) {
  FILE * f = fopen(fname, "r");
  if (f == NULL)
  {
    perror("Could not open the file!");
    return NULL;
  }

  kvarray_t * kv_pair_array = malloc(sizeof(*kv_pair_array));
  kv_pair_array->kvarray = NULL;
  kv_pair_array->arrayLength = 0;

  char* line = NULL;
  size_t sz = 0;
  kvpair_t * current_kvpair = NULL;
  int idx = 0;
  while((getline(&line, &sz, f))>=0)
  {
    current_kvpair=splitKV(line);
    kv_pair_array->kvarray = realloc(kv_pair_array->kvarray, (idx+1)*(sizeof(*(kv_pair_array->kvarray))));
    kv_pair_array->kvarray[idx] = current_kvpair;
    current_kvpair = NULL;
    line = NULL;
    idx++;
  }
  kv_pair_array->arrayLength = idx;

  free(line);

  if(fclose(f)!=0)
  {
    perror("Error closing the file");
    return NULL;
  }
  return kv_pair_array;
}

void freeKVs(kvarray_t * pairs) {
  for (int i = 0; i< pairs->arrayLength; i++)
  {
    free(pairs->kvarray[i]->key);
    free(pairs->kvarray[i]);
  }
  free(pairs->kvarray);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  for (int i = 0; i< pairs->arrayLength; i++)
  {
    printf("key = '%s' value = '%s'\n", pairs->kvarray[i]->key, pairs->kvarray[i]->value);
  } 
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  for(int i = 0; i<pairs->arrayLength; i++)
  {
    if((strcmp(pairs->kvarray[i]->key, key)) == 0)
      return (pairs->kvarray[i]->value);
  }
  return NULL;
}
