#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

typedef struct Lnode{

	char name[1024];
	int num;
	int data;

	struct Lnode *next;
}LNODE;


void linkCreate(LNODE **p_head){

	LNODE *data_head=NULL;
	data_head =(LNODE *)malloc(sizeof(LNODE));
	printf("please input the value name ,num ,data:\n");
	scanf("%s %d %d",data_head->name,&data_head->num,&data_head->data);

	//给头结点赋值
	LNODE *pb= *p_head;

	//没有头结点
	if(*p_head==NULL){
	    *p_head=data_head;
	    data_head->next=NULL;
	}

	//有头结点 遍历至没有头结点
	else {
	    while(pb->next!=NULL){
	    	pb=pb->next;
	    }

	    pb->next=data_head;
	    data_head->next=NULL;
	}

}


void printLink(LNODE *node_head){


	printf("enter print link \n");

	LNODE *p_move=node_head;


	if(p_move==NULL)
	    printf("link is NULL\n");

	while(p_move!=NULL){
	    printf("name is %s,num is %d,data is %d\n",p_move->name,p_move->num,p_move->data);
	    p_move = p_move->next;
	
	}


}


bool linkOrder(LNODE *l){
	
	LNODE *pb,*pf,temp;
	pb = l;
	
	if(l==NULL){
	    printf("not need to order\n");
	    return false;
	}

	while(pb->next!=NULL){
	    
	    pf=pb->next;
	    while(pf!=NULL){
	       
		if(pb->num>pf->num){
	            temp=*pb;
		    *pb=*pf;
		    *pf=temp;
	    
	            temp.next=pb->next;
		    pb->next=pf->next;
		    pf->next=temp.next;
	         }
	       	    
		 pf=pf->next;
	    } 

	    pb=pb->next;
	}
	return true;
}

LNODE *linkreverse(LNODE **l){
	LNODE *pb,*pf,*r;

	pb=*l;
	if(pb==NULL||pb->next==NULL){
	    printf("not need to reverse\n");
	}

	pf = pb->next;
	while(pf!=NULL){
	    r=pf->next;
	    pf->next=pb;

	    pb=pf;
	    pf=r;
	}

	(*l)->next=NULL;
	return pb;
}

int main(){

	LNODE *p_head=NULL;

	linkCreate(&p_head);
	linkCreate(&p_head);
	linkCreate(&p_head);
	printLink(p_head);
	
	int flag = linkOrder(p_head);
	printf("flag is %d\n",flag);
	printLink(p_head);


	LNODE *l_rev = linkreverse(&p_head);
	printLink(l_rev);

	return 0;
}
