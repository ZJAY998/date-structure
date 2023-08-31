#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
#define MAXSIZE 1024

typedef struct Queue{
    int front;	//queue head
    int rear;   //queue end

    int data[MAXSIZE];
}CirQueue;

//cirqueue empty and full 
//
//empty
//front == rear 
//
//full
//front == rear && (rear+1)%MAXSIZE == front

CirQueue* Create();                        //init 
int getLength(CirQueue* Sq);               //get length
int IsEmpty(CirQueue* Sq);                 //check queue is empty
void Insert(CirQueue* Sq, int val);        //queue in 
int Del(CirQueue* Sq);              	   //queue out
int GetHead(CirQueue* Sq);          	   //get queue head element
void Clear(CirQueue* Sq);           	   //clear queue
void Destory(CirQueue* Sq);         	   //free queue

void Clear(CirQueue* sq){
    sq->front = sq->rear = -1;
    printf("CirQueue queue clear\n");
};

void Destory(CirQueue* sq){
    free(sq);
    printf("CirQueue queue destroy\n");
    sq = NULL;
};

CirQueue* Create(){

      CirQueue* sq = (CirQueue *)malloc(sizeof(CirQueue)+1);
      sq->front = sq->rear = -1;
      memset(sq->data,0,MAXSIZE*sizeof(int));
      
      return sq;
};


int getLength(CirQueue* sq){
    if(NULL!=sq){
        return sq->rear - sq->front;
    }
    return -1;
}; 

int IsEmpty(CirQueue* sq){

    if(sq->front == sq->rear){
         return 1;
    }

    return 0;
};

//queue first is front ,last is rear
void Insert(CirQueue* sq, int val){
    //check is full
    if((sq->rear+1)%MAXSIZE == sq->front){
        printf("queue is full.\n");
        return;	
    }

    //check is empty or not 
    if(sq->front == sq->rear){
        sq->front = sq->rear = 0;
        sq->data[sq->rear] = val;
        sq->rear++;
    }
    else
    {
    
        sq->data[sq->rear] = val;
	sq->rear=(sq->rear+1)%MAXSIZE;
    }
    
    
};

int Del(CirQueue* sq){

    if(sq->front == sq->rear){
 
     	return -1;
    }
 
    else{

	int temp = sq->data[sq->front];
	sq->front = (sq->front+1)%MAXSIZE;

	return temp;
    }
};

int GetHead(CirQueue* sq){

    if(sq->front == sq->rear){
        return -1;
    }else{
        int q_head = sq->data[sq->front];
	return q_head;
    }


};

int main(){
    CirQueue *cir;

    cir = Create();
    
    Insert(cir,100);
    Insert(cir,101);
    Insert(cir,102);
    Insert(cir,103);
    Insert(cir,99);

    int getHead = GetHead(cir);
    printf("get head is %d\n",getHead);

    int getLen = getLength(cir); 
    printf("get length is %d\n",getLen);
    printf("get del num is %d\n",Del(cir));
    printf("get del num is %d\n",Del(cir));
    printf("get del num is %d\n",Del(cir));
    printf("get del num is %d\n",Del(cir));
    printf("get del num is %d\n",Del(cir));
    printf("get del num is %d\n",Del(cir));
    int getLen1 = getLength(cir); 
    printf("get length is %d\n",getLen1);

    Clear(cir);                  //clear queue
    Destory(cir);                //free queue


    return 0;
}
