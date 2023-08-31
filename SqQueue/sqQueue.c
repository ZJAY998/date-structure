#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024

typedef struct Queue{
    int front;	//queue head
    int rear;   //queue end

    int data[MAXSIZE];
}SeqQueue;


SeqQueue* Create();                        //init 
int getLength(SeqQueue* Sq);               //get length
int IsEmpty(SeqQueue* Sq);                 //check queue is empty
void Insert(SeqQueue* Sq, int val);        //queue in 
int Del(SeqQueue* Sq);              	   //queue out
int GetHead(SeqQueue* Sq);          	   //get queue head element
void Clear(SeqQueue* Sq);           	   //clear queue
void Destory(SeqQueue* Sq);         	   //free queue

void Clear(SeqQueue* sq){
    sq->front = sq->rear = -1;
    printf("queue clear\n");
};

void Destory(SeqQueue* sq){
    free(sq);
    printf("queue destroy\n");
    sq = NULL;
};

SeqQueue* Create(){

      SeqQueue* sq = (SeqQueue *)malloc(sizeof(SeqQueue)+1);
      sq->front = sq->rear = -1;
      memset(sq->data,0,MAXSIZE*sizeof(int));
      
      return sq;
};


int getLength(SeqQueue* sq){
    if(NULL!=sq){
        return sq->rear - sq->front;
    }
    return -1;
}; 

int IsEmpty(SeqQueue* sq){

    if(sq->front == sq->rear){
         return 1;
    }

    return 0;
};

//queue first is front ,last is rear
void Insert(SeqQueue* sq, int val){
    //check is max 
    if(sq->rear == MAXSIZE-1){
        printf("queue is full.\n");
        return;	
    }

    //check is empty or not 
    if(sq->front == sq->rear){
        sq->front = sq->rear = 0;
    }
    
    sq->data[sq->rear] = val;
    sq->rear++;
    
};

int Del(SeqQueue* sq){

    if(sq->front == sq->rear){
 
     	return -1;
    }
 
    else{
	int temp = sq->data[sq->front];
        sq->front++;
	
	return temp;
    }
};

int GetHead(SeqQueue* sq){

    if(sq->front == sq->rear){
        return -1;
    }else{
        int q_head = sq->data[sq->front];
	return q_head;
    }


};

int main(){
    SeqQueue *s;

    s = Create();
    
    Insert(s,100);
    Insert(s,101);
    Insert(s,102);
    Insert(s,103);
    Insert(s,99);

    int getHead = GetHead(s);
    printf("get head is %d\n",getHead);

    int getLen = getLength(s); 
    printf("get length is %d\n",getLen);
    printf("get del num is %d\n",Del(s));
    printf("get del num is %d\n",Del(s));
    int getLen1 = getLength(s); 
    printf("get length is %d\n",getLen1);

    Clear(s);                  //clear queue
    Destory(s);                //free queue


    return 0;
}
