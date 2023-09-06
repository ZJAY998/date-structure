#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

typedef struct BitNode{

    int data;
    struct BitNode *lchild,*rchild;
} BitNode,*BiTree;

//search the key in tree
// found 0 , not found -1
//BiTree SearchBST(BiTree *T,int key,BiTree f,BiTree* p)
BitNode* SearchBST(BitNode *T,int key,BitNode *f,BitNode **p)
{
   //Tree is NULL
   if(NULL == T){
       *p = f;
       g_warning("in searchBST , tree is NULL\n");

       return NULL;
   }


   else if(T->data == key){
       *p = T;
       g_warning("in searchBST , key == t->data \n");

       return T;
   }

   else if(T->data > key){
       return SearchBST(T->lchild,key,T,p);
   }

   else{
       return SearchBST(T->rchild,key,T,p);
   }
}


int InsertBST(BitNode **T,int key){

    BitNode *p,*s;
    
    //not found ,tree is no key
    if(!SearchBST(*T,key,NULL,&p)) {
        printf("enter malloc the BiTnode\n");
        s = (BitNode *)malloc(sizeof(BitNode));
	s->data = key;
        s->lchild = s->rchild = NULL;
     
	if(!p){
	   *T = s; // s -> root
	   printf("T insert root\n");
	}

	else if (key < p->data){ //left
       	   printf("lchild , s->data is %d \n",s->data);
	   p->lchild = s;
	}

	else{
       	   printf("rchild , s->data is %d \n",s->data);
	   p->rchild = s;
	}


	return 0;
    }

    else{
	return -1;
    }
}


int Delete(BiTree *p){
    BiTree q,s;
    
    if( (*p)->rchild == NULL){
        q = *p;
        *p = (*p)->lchild;
	free(q);
    }
    
    else if((*p)->rchild == NULL){
        q = *p;
	*p = (*p)->rchild;
        free(q);
    }

    else{
	q = *p;
	s = (*p)->lchild;
	while(s->rchild){
	   q = s;
	   s = s->rchild;
	}

	(*p)->data = s->data;
	if(q!=*p){
	     q->rchild = s->lchild;
	}
	else{
	     q->lchild = s->lchild;
	}

	free(s);
    }

    return 0;
}

//delete the tree
int DeleteBST(BiTree *T,int key){
    if(!*T) //  tree null
    {
        return -1;
    }

    else
    {
        if(key == (*T)->data)
	{
	    return Delete(T);
	}

	else if (key < (*T)->data){
	    return DeleteBST(&(*T)->lchild,key);
	}

	else
	    return DeleteBST(&(*T)->rchild,key);
    
    }
}


int main(){
    
    BitNode *bit = NULL;
    printf("flag insert is %d\n",InsertBST(&bit,50));
  
   
    printf("flag insert is %d\n",InsertBST(&bit,20));
    
    printf("flag insert is %d\n",InsertBST(&bit,60));
    if(NULL!=bit){
       printf("tree data is %d\n",bit->data);
       if(NULL!=(bit->lchild))
           printf("tree lchild data is %d\n",bit->lchild->data);
       if(NULL!=(bit->rchild))
           printf("tree rchild data is %d\n",bit->rchild->data);

    }
   

    //if(NULL!=bit){
    //   printf("tree data is %d\n",bit->data);
    //}

    //tree = (BiTree)malloc(sizeof(BiTNode));
    //tree->data = 100;
    //tree->lchild = tree->rchild = NULL;
    
//   BiTree p,s;
//   printf("search flag  %s\n",SearchBST(tree,100,NULL,&p));
//   printf("search flag  %s\n",SearchBST(tree,999,NULL,&p));
//   printf("search flag  %s\n",SearchBST(tree,50,NULL,&p));

    return 0;
}
