#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n)
{
  if(n==0){return 0;}
  int maxNum = 1;
  int backup_maxNum=1;//{1,2,3, 2,1,9,8,7,8,2}
  for (int counter = 1; counter<n; counter++)
  {
      if(array[counter]>array[counter-1])
	maxNum++;
      else
      {
	if (maxNum>backup_maxNum)
	{
	  backup_maxNum = maxNum;//back =3 
	  maxNum=1;
	}
	else
	  maxNum = 1;
      }
  }
  if (maxNum<backup_maxNum){maxNum = backup_maxNum;}
  return maxNum;
}
