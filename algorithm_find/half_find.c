#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int half_find(int arr[],const int num,int begin,int last)
{
    int mid = 0;

    if(begin > last){
        return -1;
    }

    while(begin <= last){
        mid = (begin + last) / 2;
	if (num == arr[mid]){
	    return mid;
	}

	else if (arr[mid] < num){
	    begin = mid + 1;
	}

	else if (arr[mid] > num){
	    last = mid - 1;
	}
    }
   
        return -1;
}


int half_bifind(int arr[],const int num,int begin,int last)
{
    int mid = -1;
  
    mid = (begin + last)/2;
    
    if(num == arr[mid]){
        return mid;
    }
    
    else if(arr[mid] > num){
        return half_bifind(arr,num,begin,mid-1);
    }

    else if(arr[mid] < num){
        return half_bifind(arr,num,mid+1,last);
    }
    
    return -1;
}



int main(){

    int arr[]={1,2,3,4,5,6,7};

    int flag = half_find(arr,1,0,6);
    printf("find flag is %d\n ",flag);
    printf("find flag is %d\n ",half_find(arr,7,0,6));
   
    int flag_new = half_bifind(arr,6,0,6);
    printf("find flag_new is %d\n ",flag_new);
    printf("find flag_new is %d\n ",half_bifind(arr,1,0,6));
    printf("find flag_new is %d\n ",half_bifind(arr,2,0,6));
    printf("find flag_new is %d\n ",half_bifind(arr,3,0,6));
    printf("find flag_new is %d\n ",half_bifind(arr,4,0,6));
    printf("find flag_new is %d\n ",half_bifind(arr,5,0,6));
    printf("find flag_new is %d\n ",half_bifind(arr,6,0,6));
    printf("find flag_new is %d\n ",half_bifind(arr,7,0,6));

    return 0;
}
