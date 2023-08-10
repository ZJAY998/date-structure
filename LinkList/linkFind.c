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
	    printf("enter not head node\n");
	    *p_head=data_head;
	    data_head->next=NULL;
	}

	//有头结点 遍历至没有头结点
	else {
	    printf("enter have head node\n");
	    while(pb->next!=NULL){
	    	pb=pb->next;
	    }

	    pb->next=data_head;
	    data_head->next=NULL;
	}

}

bool linkNumfind(LNODE *l){

	printf("please input the num you find:\n");
	
	int findNum = 0;
	scanf("%d",&findNum);
	
	LNODE *p_move = l;

	while(p_move!=NULL){
	
	    	printf("name is %s,num is %d,data is %d\n",p_move->name,p_move->num,p_move->data);
	
		if(findNum==p_move->num){
		    printf("find the num  %d in link\n",findNum);
		    return true;
		}
		p_move=p_move->next;
	}
	
	printf("not found it\n");
	return false;
}

bool linkfindBynum(LNODE *l,int num){

	if(num<=0){
	    printf("not found the num %d\n",num);
	    return false;
	}

	int j=1;
        LNODE *p_move = l;
        while(p_move!=NULL && j<num){
                p_move=p_move->next;
		j++;
        }

	printf("j is %d\n",j);

	if(p_move!=NULL){
        	printf("find the num  %d in link name is %s ,num is %d\n",num,p_move->name,p_move->data);
        	return true ;
	}

	printf("not found the num %d\n",num);
	return false;
}


bool ListInsert(LNODE **l,int i,LNODE p_data){

	if(i<1)
	    return false;

	//没有头结点
	if(i==1){
	    LNODE *s=(LNODE*)malloc(sizeof(LNODE));
	    s->data=p_data.data;
            strncpy(s->name,p_data.name,strlen(p_data.name));
            s->num=p_data.num;
	    s->next=*l;
	    *l=s;
	    return true;
	}

	LNODE *p; //指针p指向扫描的结点
	int j = 1;//当前是第几个节点
	p=*l;//l指向头结点  
	
	if(NULL==p)
            return false;

	//插入n个节点
	while(p!=NULL && j<i-1){
	    p=p->next;
	    j++;
	}

	LNODE *s=(LNODE*)malloc(sizeof(LNODE));
	s->data=p_data.data;
	strncpy(s->name,p_data.name,strlen(p_data.name));
	s->num=p_data.num;
	s->next=p->next;
	p->next=s;
	return true;

}


void printLink(LNODE *node_head){


	printf("enter print link \n");

	LNODE *p_move=node_head;
	while(p_move!=NULL){
	    printf("name is %s,num is %d,data is %d\n",p_move->name,p_move->num,p_move->data);
	    p_move = p_move->next;
	
	}


}

int main(){

	LNODE *p_head=NULL;

	//linkCreate(&p_head);
	//linkCreate(&p_head);
	//linkCreate(&p_head);
	//printLink(p_head);
	
	LNODE p_data1;
	LNODE p_data2;
	LNODE p_data3;

	strncpy(p_data1.name,"qaq",strlen("qaq")+1);
	p_data1.num=111;
	p_data1.data=1;

	strncpy(p_data2.name,"qqq",strlen("qqq")+1);
	p_data2.num=222;
	p_data2.data=2;
	

	strncpy(p_data3.name,"aaa",strlen("aaa")+1);
	p_data3.num=333;
	p_data3.data=3;
	
	ListInsert(&p_head,1,p_data1);
	ListInsert(&p_head,2,p_data2);
	ListInsert(&p_head,3,p_data3);

	printLink(p_head);


	//linkNumfind(p_head);

	linkfindBynum(p_head,0);
	linkfindBynum(p_head,1);
	linkfindBynum(p_head,2);
	linkfindBynum(p_head,3);
	linkfindBynum(p_head,4);
	linkfindBynum(p_head,5);

	return 0;
}
