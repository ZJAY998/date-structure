#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int sq_find(int arr[],int n,int key)
{
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
	    return i;
	}
    }
    return -1;
}

//return arr[] index 
//if zero is not found 
int sq_find_new(int arr[],int n,int key){
    int i = n;
    arr[0] = key;//set the sentinel
    while(arr[i]!=key){
         i--;
    }
  
    return i;  
}


int main(){

    int arr[]={10,11,9,22,0,100};

    int flag = sq_find(arr,6,9);
    printf("find flag is %d\n ",flag);
   
    int flag_new = sq_find_new(arr,6,100);
    printf("find flag_new index is %d\n ",flag_new);

    return 0;
}
