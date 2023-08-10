#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


#define MAXSIZE 10
#define INITSIZE 10

typedef struct{
	int data[MAXSIZE];
	int length;
}SqList;


//动态表
typedef struct{
	int *data;
	int length;
	int MaxSize;
}SqList_new;


//初始化顺序表
static void InitList(SqList *l){
	l->length=8;
	for(int i=0;i<8;i++){
		l->data[i]=i;//初始化数据默认值为0
	}

	printf("length is %d\n",l->length);
}


//插入静态操作  
bool InsertList(SqList *l,int i,int e){

	if(i<1||i>l->length+1||l->length>MAXSIZE)
		return false;
	
	int last = 0;
	for(int j=l->length;j>=i;j--)
		l->data[j]=l->data[j-1];
	
	l->data[i-1]=e;
	l->length+=1;

	return true;
}

//打印对应顺序表
static void printList(SqList l){
	printf("l.max is %d\n",l.length);
	for(int i=0;i<l.length;i++){
		printf("%d \t",l.data[i]);
	}
	printf("\n");
}



int main(){


	SqList l;
	InitList(&l);

	printList(l);

	int result = InsertList(&l,5,10);
	printf("result is %d\n",result);
	printList(l);
	

	return 0;
}
