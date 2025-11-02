//Insertion Sort Algorithm

#include <stdio.h>

int insertionsort(int numbers[], int size){
int temp;
for(int i=1; i<size; i++){
    int j=i;
    while(j>0 && numbers[j] < numbers[j-1]){
        temp = numbers[j];
        numbers[j] = numbers[j-1];
        numbers[j-1] =temp;
        --j;
    }
}
    
    
}

int main() {

    int input;
    printf("Enter the size:");
    scanf(" %d", &input);
    int *arr = (int *)malloc(input * sizeof(int));
    if (arr == NULL) {
        // Handle error if allocation fails
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the array:");
    for(int i=0; i < input; i++  ){
      scanf("%d", &arr[i]);  
    }
     
     insertionsort(arr, input);
     printf("sorted :");
    for(int i=0; i < input; i++  ){
      printf("%d ", arr[i]);  
    }
     

    free(arr);
    return 0;
}
