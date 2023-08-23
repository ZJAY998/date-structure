#include<stdio.h>
#include<stdlib.h>

int getSum(int n){
    if(n==1)
        return 1;
    
    int temp = getSum(n-1);

    return temp + n;
}

int main(){
    int sum;
    int n;
    printf("please intput n:\n");
    scanf("%d",&n);

    sum=getSum(n);
    printf("get result %d\n",sum);

    return 0;
}
