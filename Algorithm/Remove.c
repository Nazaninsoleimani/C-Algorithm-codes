#include <stdio.h>
int myremove(int A[], int size, int d){
   if(size == 0) return -1;
   int index = search(A, size, d);
   if(index < 0 ) return -2;
   
   for(int i =index; i<size-1; i++){
       A[i] = A[i+1];
   }
   return 0;
}
