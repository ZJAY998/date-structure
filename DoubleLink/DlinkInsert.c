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
	return;
    }

    //插入的数比之前的数大 遍历至后
    while(p_new->num>=(*l)->num && pb->next!=NULL){
      pb = pb->next;
    }

    //插入的数比前的小  2种情况 
    if(p_new->num < (*l)->num){
       
	//插入为头结点 插在头结点前面
        if(pb==*l){
            p_new->next=pb;
	    (*l)->front=p_new;
	    p_new->front=NULL;
	    *l=p_new;
        }
	else
	//不为头结点  pf 记录上个结点位置
	{
            pf =pb->front;

	    p_new->next=pb;
	    p_new->front=pf;
	    pf->next=p_new;
	    pb->front=p_new;
	}
    }
   
    else{
      pb->next=p_new;
      p_new->front=pb;
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
//	printf("-------------------\n");
//	while(p_move!=NULL){
//	    printf("name is %s,num is %d\n",p_move->name,p_move->num);
//	    p_move=p_move->front;
//	}
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

    //insert p_new_insert
    DNODE *p_new1=NULL;
    p_new1=(DNODE*)malloc(sizeof(DNODE));
    printf("input p_new insert1 the name  num \n");
    scanf("%s %d",p_new1->name,&p_new1->num);

    double_link_insert_num(&head,p_new1);
    double_link_print(head);

    return 0;
}
