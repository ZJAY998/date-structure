#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024

typedef struct Node pNode;

struct Node{
    int data;    //data
    pNode* next;
};



typedef struct Queue{
    pNode* front;  //pnode queue head
    pNode* rear;   //pnode queue end
    int length;   //pnode length 
}LQueue;


LQueue* Create();                          //init 
int getLength(LQueue* lsq);                //get length
int IsEmpty(LQueue* lsq);                  //check queue is empty
void Insert(LQueue* lsq, int val);         //queue in 
int Del(LQueue* lsq);              	   //queue out
int GetHead(LQueue* lsq);          	   //get queue head element
void Clear(LQueue* lsq);           	   //clear queue
void Destory(LQueue* lsq);         	   //free queue

void Clear(LQueue* sq){
    sq->front = sq->rear = NULL;
    sq->length = 0;
    printf("Squeue clear\n");
};

void Destory(LQueue* sq){

    if(NULL!=sq)
    {
        free(sq);
        printf("queue destroy\n");
        sq = NULL;
    }	    
};

LQueue* Create(){

      LQueue* lq = (LQueue *)malloc(sizeof(LQueue)+1);
      
      lq->front = NULL;
      lq->rear = NULL;
      lq->length = 0;

};


int getLength(LQueue* sq){
    if(NULL!=sq){
        return sq->length;
    }
    return -1;
}; 

int IsEmpty(LQueue* sq){

    if(sq->length == 0){
         return 1;
    }

    return 0;
};

//queue in
void Insert(LQueue* sq, int val){

    pNode *pn = (pNode *)malloc(sizeof(pNode)+1);
    pn->data = val;
    pn->next = NULL;

    //if empty in head
    if(sq->length == 0){
        sq->front = pn;
	sq->rear = pn;
    }else{
        sq->rear->next = pn;
	sq->rear = pn;
    }

    sq->length++;
};


int Del(LQueue* sq){

    if(sq->length==0){
 
     	return -1;
    }
 
    else{
	pNode* pTmp = sq->front;
	sq->front = pTmp->next;
	sq->length--;
	
	return pTmp->data;
    }
};

int GetHead(LQueue* sq){

    if(sq->length==0){
        return -1;
    }else{
        int q_head = sq->front->data;
	return q_head;
    }
};

int main(){
    LQueue *lq;

    lq = Create();
    
    Insert(lq,1000);
    Insert(lq,1001);
    Insert(lq,1002);
    Insert(lq,1003);
    Insert(lq,998);

    int getHead = GetHead(lq);
    printf("get head is %d\n",getHead);

    int getLen = getLength(lq); 
    printf("get length is %d\n",getLen);
    printf("get del num is %d\n",Del(lq));
    printf("get del num is %d\n",Del(lq));
    printf("get del num is %d\n",Del(lq));
    printf("get del num is %d\n",Del(lq));
    printf("get del num is %d\n",Del(lq));
    printf("get del num is %d\n",Del(lq));
    printf("get del num is %d\n",Del(lq));
    int getLen1 = getLength(lq); 
    printf("get length is %d\n",getLen1);

    Clear(lq);                  //clear queue
    Destory(lq);                //free queue


    return 0;
}
