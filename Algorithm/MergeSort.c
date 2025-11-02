//Merge Sort Algorithm

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void merge(int numbers[], int i,int j ,int k){
  int mergedSize = (k - i) + 1;
 
    int *mergedNumbers = (int *)malloc(mergedSize * sizeof(int));
    
    if (mergedNumbers == NULL) {
        fprintf(stderr, "Error: Memory allocation failed in merge function.\n");
        return; 
    }
  int mergepos =0 ;
  int leftpos =i;
  int rightpos = j+1;
  
  while(leftpos <= j && rightpos <= k){
      if(numbers[leftpos] <= numbers[rightpos]){
          mergedNumbers[mergepos] = numbers[leftpos];
          leftpos++;
      }else{
          mergedNumbers[mergepos] = numbers[rightpos];
          rightpos++; 
      }
      ++mergepos;
  }
  while(leftpos <= j){
      mergedNumbers[mergepos] = numbers[leftpos];
      ++leftpos;
      ++mergepos;
  }
  while(rightpos <= k){
      mergedNumbers[mergepos] = numbers[rightpos];
      ++rightpos;
      ++mergepos;
  }
  for(mergepos=0; mergepos < mergedSize; mergepos++){
      numbers[i + mergepos] = mergedNumbers[mergepos];
  }
  free(mergedNumbers);
}

void Mergesort(int numbers[], int i, int k){
 int j;
 if(i<k){
   j = (i+k)/2;  
 
 Mergesort(numbers, i, j);
 Mergesort(numbers, j+1, k);
 
 merge(numbers, i, j , k);
 }
}

int main()
{
   int input;
    printf("Enter the size:");
    scanf(" %d", &input);
    int *arr = (int *)malloc(input * sizeof(int));
    if (arr == NULL) {
        // Handle error if allocation fails
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the array: (unsorted) ");
    for(int i=0; i < input; i++  ){
      scanf("%d", &arr[i]);  
    }
    
 
    Mergesort(arr, 0, input-1);
     printf("sorted array : ");
    for(int i=0; i < input; i++  ){
      printf("%d ", arr[i]);  
    }
    free(arr);
    return 0;
}
