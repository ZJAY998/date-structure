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

//按位删除  
int linkDelete(LNODE **node_head,int i,int *data){

	//头结点判断
	if(i<1)
	    return false;
	
	//p_data 指向当前节点
	LNODE *p_data=NULL;
	p_data=*node_head;

	int j=0;

	while(NULL!=p_data&&j<i-1){
		p_data=p_data->next;
		j++;
	}

	if(p_data==NULL | p_data->next==NULL)
		return false;
	

	LNODE *q=p_data->next;//指向删除的节点
	*data=q->num;//返回删除的节点值
	p_data->next=q->next;//将*q从链中断开

	free(q);
	return true;
		
}

void linkDelByName(LNODE **l){

    LNODE *pb=NULL;
    LNODE *pf=NULL;

    pb = *l;
    if(pb==NULL){
        printf("no link to delete \n");
    }

    else{
    
        printf("please input the name you del:\n");
        char name[128]={0};
        scanf("%s",name);
        while(strncmp(name,pb->name,strlen(name))!=0&&pb->next!=NULL){
	   pf = pb;
	   pb = pb->next;	
	}

	if(strncmp(name,pb->name,strlen(name))==0){
	    printf("found the point \n");

	    if(pb==*l){
	       *l = pb->next;
	    }
            
	    else{
	       pf->next=pb->next;
	    
	    }

	    free(pb);
	}
    
        else{
	
	    printf("not found the name\n");
	}
    }

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


	linkDelByName(&p_head);
	printLink(p_head);




	return 0;
}
