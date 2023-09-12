#include <stdio.h>

int arr[10]= {9, 0, 2, 8, 1, 4, 6, 3, 7, 5 };

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[],int low,int high){
   int last = arr[high];
   int i = (low-1);

   for(int j = low;j<=high-1;j++){
       if(arr[j]<last){
           i++;
	   swap(&arr[i],&arr[j]);
       }
   }
   swap(&arr[i+1],&arr[high]);
   return i+1;

}

void QuickSort(int arr[],int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);
	
	QuickSort(arr,low,pi-1);
	QuickSort(arr,pi+1,high);
    
    }
}

int main(){

    for(int i = 0;i<10;i++){
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    QuickSort(arr,0,9);

    printf("after sort------------------\n");

    for(int i = 0;i<10;i++){
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}
