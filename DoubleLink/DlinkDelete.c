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


void double_link_print(DNODE *l){

	DNODE *p_move=l;

	if(p_move==NULL){
	
            printf("no point\n");
	    return;
	}

	while(p_move!=NULL){
	    printf("name is %s,num is %d\n",p_move->name,p_move->num);
	    p_move=p_move->next;
	}

//	printf("name is %s,num is %d\n",p_move->name,p_move->num);
//	printf("-------------------\n");
	
//	while(p_move!=NULL){
//	    printf("name is %s,num is %d\n",p_move->name,p_move->num);
//	    p_move=p_move->front;
//	}

}


void double_link_del_by_num(DNODE **l){

    DNODE *pb,*pf;
    pb=*l;
    if(*l==NULL){
	 printf("link is empty\n");
         return;
    }


    int num=-1;
    printf("input the num you del:");
    scanf("%d",&num);


    while((pb->num!=num) && (pb->next!=NULL)){
       pb=pb->next;
    }

    //2 种情况 头结点 不是头 
    if(pb->num==num){

	if(pb==*l){

            //只有一个结点
	    if((*l)->next==NULL){
	        *l=pb->next;
	    }
	    else//多个节点
	    {
	        *l=pb->next;
	        (*l)->front=NULL;   
	    }        

        }
   
       	else{
        //其他节点

            if(pb->next!=NULL){
	
	        pf=pb->front;//pf 指向pb的前一个节点
	        pf->next=pb->next;
	        (pb->next)->front=pf;
	    }else{
	    
	        //删除尾结点
	        pf=pb->front;
                pf->next=NULL;
	       
	        }
           }
 
        free(pb);
    }

    else{
    
        printf("not found the num to delte\n");
    
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


    double_link_del_by_num(&head);
    double_link_print(head);
    
    double_link_del_by_num(&head);
    double_link_print(head);
    return 0;
}
