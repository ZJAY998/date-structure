#include<stdio.h>
#include<stdlib.h>


#define HASHSIZE 20

typedef struct HashTable{
    int *elem;
    int count;
}HashTable;


int m = 0;//globle hash length


//hash table init 
void InitHashTable(HashTable* h){

    m = HASHSIZE;
    h->count = m;
    h->elem = (int *)malloc(m*sizeof(int));

    for(int i=0;i < m;i++)
        h->elem[i] = NULL;
    
    return;
}

//struct hash fun
int Hash(int key)
{
    return key % m;
}

//insert
void InsertHash(HashTable* h,int key)
{
    int addr = Hash(key); //get hash addr
    while(h->elem[addr]!=NULL)
        addr = (addr + 1) % m; //Linear detection method to handle conflicts
    h->elem[addr] = key;

    printf("Insert key is %d\n", h->elem[addr]);
}

//search
int SearchHash(HashTable h,int key, int *addr)
{
    *addr = Hash(key);
    while(h.elem[*addr]!=key)
    {
        *addr = (*addr + 1) % m;
	if(h.elem[*addr] == NULL || *addr == Hash(key)) //elem end and value equal exit 
	    return 0;
    
    }
    
    return 1;
}

int main(){

    HashTable h;

    InitHashTable(&h);

    int arr[] = {10,29,33,44,51,100,98,101,2,1};

    for(int i=0;i<10;i++){
        InsertHash(&h,arr[i]);
    }

    int num = 0;
    while(1){
    printf("intput the num to find :");
    scanf ("%d",&num);

    int addr = Hash(num);
    int flag = SearchHash(h,num,&addr);
 
    printf("num is %d\n",num);  
    if(flag){
        printf("find the num %d\n",num);
    }
    else
	printf("not found\n");

    }

    return 0;
}
