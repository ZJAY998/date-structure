#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;    //数据
    struct pNode *next;  //指针
}pNode;


typedef struct Stack {
    struct Node *top;    //栈顶元素
    int size;     //栈大小
}LinkStack;


//create link
LinkStack *Create(){
    LinkStack *lstack = (LinkStack *)malloc(sizeof(LinkStack));
    if(lstack!=NULL){
        lstack->top=NULL;
	lstack->size=0;
    }

    return lstack;
}

//check is empty
int IsEmpty(LinkStack *lstack){
    if(lstack->top==NULL||lstack->size==0){
        return 1;
    }

    return 0;
}

//get statck size
int getSize(LinkStack *lstack){
    return lstack->size;
}

//get statck top
pNode *getTop(LinkStack *lstack){
    if(lstack->size!=0)
        return lstack->top;
    return NULL;
}

//statck push
int Push(LinkStack *lstack,int val){

    pNode *node = (pNode *)malloc(sizeof(pNode));
    if(node!=NULL){
        node->data = val;
	node->next=getTop(lstack);
	lstack->top=node;
	lstack->size++;
    }
    
    else
        return 0;     

    return 1;
}

//stack pop
pNode *Pop(LinkStack *lstack){

    if(IsEmpty(lstack))
        return NULL;

    pNode *node = lstack->top;
    lstack->top = lstack->top->next;
    lstack->size--;
    return node;
}

void Destory(LinkStack *lstack){

    if(IsEmpty(lstack)){
        free(lstack);
	printf("stack is null , end !\n");
	return;
    }

    do{
        pNode *pTmp;
	pTmp = Pop(lstack);
	free(pTmp);
    }while(lstack->size>0);
    
    printf("destory\n");

}

int main(){

    srand((unsigned)time(0));

    LinkStack *lstack=NULL;
    lstack = Create();

    //check empty
    int ret = IsEmpty(lstack);

    if(ret){
        printf("stack is null\n");
    }else{
        printf("stack is not null\n");
    }


    for(int i = 0; i < 10; i++)
    {
        Push(lstack,rand() % 100);//insert random num
        //Push(lstack,i);//insert random num
    }

    ret = IsEmpty(lstack);
  
    if(ret){
        printf("stack is null\n");
    }else{
        printf("stack is not null\n");
    }

    //get stack length
    printf("stack length is %d\n",getSize(lstack));

    //get stack top
    printf("stack top is %d\n",*(int *)getTop(lstack));

    printf("stack length is %d\n",getSize(lstack));

    while(lstack->size > 0){
        printf("stack val is %d\n",*(int *)Pop(lstack));
    }

    Destory(lstack);


    return 0;
}

