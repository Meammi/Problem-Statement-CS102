#include <stdio.h>
void swap_elements(int *arr, int pos1, int pos2);

int main(){
    //input size of array
    int n = 0;
    printf("Enter the number of elements (max 100): ");
    scanf("%d",&n);
    //Validate size of array
    if(n > 100){n = 100;};

    //input the value for each index.
    int arr[n];
    int i = 0;
    printf("Enter %d numbers: ",n);
    while (i < n){
        scanf(" %d",&arr[i]);   
        i++;
    }
    
    //input swap position
    int pos1 = 0;
    int pos2 = 0;
    printf("Enter first position to swap (0-%d): ",n-1);
    scanf("%d",&pos1);
    printf("Enter first position to swap (0-%d): ",n-1);
    scanf("%d",&pos2);
    //Validate pos1 and pos2
    while (pos1 >= n||pos2 >= n)
    {
        if(pos1 >= n){
            printf("Please re-enter first position to swap (0-%d): ",n-1);
            scanf("%d",&pos1);
        }
        if(pos2 >= n){
            printf("Please re-enter second position to swap (0-%d): ",n-1);
            scanf("%d",&pos2);
        }
    }

    //call func.
    swap_elements(arr,pos1,pos2);
    
    //display result
    printf("After swapping elements at positions %d and %d: ",pos1,pos2);
    i = 0;
    while(i < n){
        printf(" %d",arr[i]);
        i++;
    }
    return 0;
}

void swap_elements(int *arr, int pos1, int pos2){
    int temp = *(arr+pos1);
    *(arr+pos1) = *(arr+pos2);
    *(arr+pos2) = temp;
}