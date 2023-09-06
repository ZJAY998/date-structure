#include <stdio.h>
#include <stdlib.h>


const int F[13]={0,1,1,2,3,5,8,13,21,34,55,89,144};

int Fibonacci_Search(int *a, int n,int key)
{
    int low,high,mid,i,k;
    low = 1;
    high = n;
    k = 0;

    while(n > F[k]-1)
        k++;

    for(i=n;i<F[k]-1;i++){
	a[i] = a[n];
    }

    while(low <= high)
    {
        mid = low+F[k-1]-1;
	if(key < a[mid])
	{
	    high = mid - 1;
	    k = k-1;
	}
    
	else if (key > a[mid])
	{
	    low = mid + 1;
	    k = k-2;
	}
    
	else
	{
	    if(mid<=n)
	    {
	        return mid;
	    }
	    else
	    {
	        return n;
	    }
	
	}
    }

    return 0;
}



int main(){

    
    int num = Fibonacci_Search(F,12,999);
    int num1 = Fibonacci_Search(F,12,144);
    printf("num is %d\n",num);
    printf("num1 is %d\n",num1);


    return 0;
}
