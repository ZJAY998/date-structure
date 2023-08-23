#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 10

typedef struct {
      int data[MAXSIZE];
      int top;
}SqStack;

//初始化stack
void InitStack(SqStack **s){
    (*s)->top=0;
}

//判断是否为空
bool StackEmpty(SqStack *s){

    if((s->top)==0)
        return true;
    else
	return false;
}

//入stack
bool Push(SqStack **s,int x){
    //判断stack 是否满
    if((*s)->top==MAXSIZE)
        return false;
  
    // 入值先 在设置坐标
    (*s)->data[(*s)->top]=x;  //新元素入栈
    (*s)->top=((*s)->top)+1;    //指针先加1

    //等价
    //(*s)->data[((*s)->top++)] = x;
    return true;

}

//出stack
bool pop(SqStack **s,int *x){
    //判断是否为空
    if((*s)->top==0)   
        return false;
    
    //先设置坐标 在取值
    (*s)->top=((*s)->top)-1;    //指针在-1
    *x = (*s)->data[(*s)->top];  //新元素出栈
    

    //stack 顶出
    //*x = (*s)->data[((*s)->top)-1];
    return true;
}

//get top value
bool getTopVal(SqStack **s,int *x){
    //check null
    if((*s)->top==0)
        return false;
 
    *x = (*s)->data[((*s)->top)-1];
    return true;


}

//free stack
void StackFree(SqStack *s){

	if(NULL!=s){
	    free(s);
	    s=NULL;
	}
}

//测试
void testStack(){
    SqStack *s;
    s=(SqStack *)malloc(sizeof(SqStack)+1);

    InitStack(&s);
    printf("stack empty flag is %d\n",StackEmpty(s));

    printf("stack push flag is %d\n",Push(&s,998));

    int out_num = -1;
    printf("stack pop flag is %d\n",pop(&s,&out_num));
    if(out_num != -1){
        printf("out num is %d\n",out_num);
    }

    
    int topVal=-1;

    printf("stack empty flag is %d\n",StackEmpty(s));
    printf("stack getTopVal flag is %d\n",getTopVal(&s,&topVal));

    if(topVal != -1){
        printf("topVal is %d\n",topVal);
    }

    printf("stack push flag is %d\n",Push(&s,999));
    printf("stack getTopVal flag is %d\n",getTopVal(&s,&topVal));

    if(topVal != -1){
        printf("topVal is %d\n",topVal);
    }

    printf("stack push flag is %d\n",Push(&s,911));
    /*
    printf("stack getTopVal flag is %d\n",getTopVal(&s,&topVal));
    if(topVal != -1){
        printf("topVal is %d\n",topVal);
    }
    */

    printf("stack push flag is %d\n",Push(&s,925));
    /*
    printf("stack getTopVal flag is %d\n",getTopVal(&s,&topVal));
    if(topVal != -1){
        printf("topVal is %d\n",topVal);
    }
    */

    printf("stack empty flag is %d\n",StackEmpty(s));
 
    printf("-------------------------------------\n");
    printf("stack pop flag is %d\n",pop(&s,&out_num));
    printf("stack pop flag is %d\n",pop(&s,&out_num));
    printf("stack pop flag is %d\n",pop(&s,&out_num));
    printf("stack pop flag is %d\n",pop(&s,&out_num));
    printf("-------------------------------------\n");

    printf("stack empty flag is %d\n",StackEmpty(s));
    StackFree(s);
}


int main(){

    testStack();

    return 0;
}
