#include <stdio.h>

int arr[10]= {9, 0, 2, 8, 1, 4, 6, 3, 7, 5 };

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertSort(int arr[],int n){

    int i , j;
    for(i = 1;i < n;i++){
        int tmp = arr[i];
	
	if(tmp > arr[i-1]){
	    for(j=i-1;j>=0 && tmp > arr[j];j--){
	        arr[j+1] = arr[j];
	        //swap(&arr[j+1], &arr[j]);
	    }    

	    arr[j+1] = tmp;
	}
    }
}

void ShellSort(int arr[],int n){
    int i,j,d;
    int tmp;

    d = n/2;

    while(d>0)
    {
        for(i=d;i<n;i++)
	{
	    tmp = arr[i];
	    j = i - d;
	    while(j >= 0 && tmp > arr[j]){
	        arr[j+d] = arr[j];
		j = j - d;
	    }

	    arr[j+d] = tmp;
	
	}

        d = d / 2;
	printf("d is %d\n",d);
    }
}


void BinarySort(int arr[],int n){
    int i,j;
    int low,high,m;
    int tmp;

    for(i=1;i<n;i++){
        tmp = arr[i];
	low = 0;
	high = i -1;
	while(low <= high){
	    m = (low + high) / 2;
	    if(tmp > arr[m])
	        high = m - 1;
	    else
	        low = m + 1;
	}

	for(j=i-1;j>=high +1;j--)
	    arr[j+1] = arr[j];

        arr[high + 1] = tmp; 
    }
}


int main(){

    for(int i = 0;i<10;i++){
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    //InsertSort(arr,10);
    //BinarySort(arr,10);
    ShellSort(arr,10);

    printf("after sort------------------\n");

    for(int i = 0;i<10;i++){
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}
