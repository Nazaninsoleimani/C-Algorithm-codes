
//binary search

#include <stdio.h>
#include <stdlib.h>

int linearsearch(int numbers[], int numsize, int key){
   int mid;
   int low; 
   int high;
   low = 0;
   high = numsize -1;
   while(high >= low){
       mid = (high + low) / 2;
       if(numbers[mid] < key){
           low = mid + 1;
       }else if(numbers[mid] > key){
           high = mid - 1;
       }else{
           return mid;
       }
   }
   return -1;
   
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

    for(int i=0; i < input; i++  ){
      scanf("%d", &arr[i]);  
    }
    
     int search;
    printf("Enter the value looking for: ");
    scanf("%d", &search);
    
    int index = linearsearch(arr, input, search);
    printf("Found index %d", index);

    free(arr);
    return 0;
}