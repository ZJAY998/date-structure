#include <stdio.h>

void swap(int *a,int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[],int n){

    int i,j,min_index;
    
    for(i = 0;i < n -1;i++){
        min_index = i;

	for(j = i + 1;j < n;j++){
	    if(arr[min_index] > arr[j]){
	        min_index = j;
	    }
	}

	if(i!=min_index)
	    swap(&arr[i],&arr[min_index]);
    }

}

int main(){

    int arr[] = {64, 25, 12, 22, 11};

    printf("原始数组:");
    for (int i = 0; i < 5; i++) 
        printf("%d ", arr[i]);
    
    printf("\n");

    selection_sort(arr, 5);

    printf("排序后的数组：");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
