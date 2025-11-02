
#include <stdio.h>
#include <stdlib.h>

int search(int A[], int size, int d){
    if(size == 0) return -1;
    int low =0;
    int high = size -1;
    
    while(high >= low){
        int mid = (high + low)/2;
        if(A[mid] > d){
            high = mid -1;
        }else if(A[mid] < d){
         low = mid  +1;
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

    printf("Enter the array: (sorted) ");
    for(int i=0; i < input; i++  ){
      scanf("%d", &arr[i]);  
    }
    
    int d;
    printf("Enter the element to search:");
    scanf(" %d", &d);
    
    int result = search(arr, input, d);
    if(result != -1){
        printf("Element found at index: %d\n", result);
    }else{
        printf("Element not found in the array.\n");
    }
    
    free(arr);
    return 0;
}