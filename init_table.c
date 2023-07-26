#include<stdio.h>
#include <stdlib.h>

typedef struct Table{
    int *head;
    int length;
    int size;
}table;

#define SIZE 10

//init table list
table initTable(){
    table t;
    t.head=(int *)malloc(SIZE*sizeof(int));
    if(!t.head){
    	printf("init error");
	exit(0);
    }

    t.length=0;
    t.size=SIZE;
    return t;
}

void displayTable(table t){

    for(int i=0;i<t.length;i++){
        printf("%d \t",t.head[i]);
    }
    printf("\n");

}

int main()
{

    table t=initTable();
    for(int i=1;i<=SIZE;i++){
        t.head[i-1]=i;
	t.length++;
    }

    printf("print\n");

    displayTable(t);
    return 0;

}
