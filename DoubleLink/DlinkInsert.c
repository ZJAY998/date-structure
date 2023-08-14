#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



typedef struct dnode{

    char name[1024];
    int  num;
    struct dnode *front;
    struct dnode *next;

}DNODE,*Dlinklist;



void double_link_create(DNODE **l,DNODE *p_new){
    DNODE *pb = *l;
    if(*l==NULL){
       *l=p_new;
       p_new->next=NULL;
       p_new->front=NULL; 
    }
    else{
    
        while(pb->next!=NULL){
	    pb=pb->next;
	}
    
	pb->next=p_new;
        p_new->front=pb;
        p_new->next=NULL;
    
    }
}

void double_link_insert_num(DNODE **l,DNODE *p_new){

    DNODE *pb,*pf;
    pb=*l;

    if(*l==NULL){
        *l=p_new;
	p_new->front=NULL;
	p_new->next=NULL;
    }


}

void double_link_print(DNODE *l){

	DNODE *p_move=l;
	
	while(p_move->next!=NULL){
	    printf("name is %s,num is %d\n",p_move->name,p_move->num);
	    p_move=p_move->next;
	}

	printf("name is %s,num is %d\n",p_move->name,p_move->num);
	printf("-------------------\n");
	
	while(p_move!=NULL){
	    printf("name is %s,num is %d\n",p_move->name,p_move->num);
	    p_move=p_move->front;
	}
}


int main(){


    DNODE *head = NULL;
    DNODE *p_new = NULL;

    int num ,i;
    printf("input the link you create:");
    scanf("%d",&num);

    if(num<=0)
        return 0;

    for(i=0;i<num;i++)
    {
        p_new=(DNODE*)malloc(sizeof(DNODE));
	printf("input the name , num \n");
	scanf("%s %d",p_new->name,&p_new->num);
    	double_link_create(&head,p_new);
    }

    double_link_print(head);

    return 0;
}
