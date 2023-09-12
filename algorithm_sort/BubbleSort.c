#include <stdio.h>

int arr[10]= {9, 0, 2, 8, 1, 4, 6, 3, 7, 5 };

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int flag = 1;
void BubbleSort(int arr[],int n){
    for(int i=0;i < n-1 && flag; i++){
	flag = 0;
        for(int j=0;j < n-i-1;j++){
	    if(arr[j]>arr[j+1]){
	        flag = 1;
	        swap(&arr[j],&arr[j+1]);
	    }
	}
    
    }

}

int main(){

    for(int i = 0;i<10;i++){
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    BubbleSort(arr,10);

    printf("after sort------------------\n");

    for(int i = 0;i<10;i++){
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}
