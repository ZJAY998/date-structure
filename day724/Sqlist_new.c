#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


#define INITSIZE 10


//动态表
typedef struct{
	int *data;
	int length;
	int MaxSize;
}SqList_new;

static void InitList_new(SqList_new *l){

	l->data=(int *)malloc(INITSIZE*sizeof(int));
	l->length=0;
	l->MaxSize=INITSIZE;

	for(int i=0;i<10;i++){
		l->data[i]=i;
	}
	l->length=10;
}

void IncreaseSize(SqList_new *l,int len){

	int *p=l->data;
	l->data=(int *)malloc((l->MaxSize+len)*sizeof(int));
	//将对应的值拷贝到新区域
	for(int i=0;i<INITSIZE;i++){
		l->data[i]=p[i];
		//strncpy(l->data,(const char *)p[i],strlen((const char *)p[i])+1);
	}

	l->length+=len;
	l->MaxSize=l->MaxSize+len;
	free(p);

}

//插入动态操作  
bool InsertList(SqList_new *l,int i,int e){

	if(i<1||i>l->length+1||l->length>l->MaxSize)
		return false;
	
	for(int j=l->length;j>=i;j--)
		l->data[j]=l->data[j-1];
	
	l->data[i-1]=e;

	//l->length+=1;
	return true;
}

//删除动态操作
bool DeleteList(SqList_new *l,int i,int *e){

	if(i<1||i>l->length)
		return false;

	*e = l->data[i-1];
	for(int j=i;j<l->length;j++)
		l->data[j-1]=l->data[j];
	
	l->length-=1;

	return true;


}

//打印对应动态
static void printList(SqList_new l){
	printf("l length is %d\n",l.length);
	for(int i=0;i<l.MaxSize;i++){
		printf("%d \t",l.data[i]);
	}
	printf("\n");
}



int main(){

	SqList_new l_new;

	InitList_new(&l_new);
	printList(l_new);

	IncreaseSize(&l_new,5);
	printList(l_new);
	
	InsertList(&l_new,10,998);

	printList(l_new);

	int a=0;//a 表示删除返回的值
	DeleteList(&l_new,10,&a);
	printList(l_new);

	printf("a is %d\n",a);

	return 0;
}
