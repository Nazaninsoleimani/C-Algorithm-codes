#include <stdio.h>
#define MAX_SIZE 1000

int MyAdd(int A[], int size, int d){
  if(size >= MAX_SIZE) return -1;
  
  int pos =0;
  while(pos < size && A[pos] < d){
   pos++;   
  }
  
  
  if(pos <size && A[pos] == d) {
      return -2;
  }
 
  
  for(int i =size ; i>pos; i--){
      A[i] = A[i-1];
  }
  A[pos] =d;
  return 0;
}
