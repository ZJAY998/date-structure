#include<stdio.h>

//add glib to use GList
//https://docs.gtk.org/glib/struct.List.html
#include<glib.h>

void each_callback(gpointer data,gpointer user_data)
{
    //printf("---------------------------------------------------------\n");
    g_print("element:%s,user param:%s\n",(gchar *)data,(gchar*)user_data);
    //printf("---------------------------------------------------------\n");
}


int main(){


    //init 
    GList *list = NULL;
    GList *llist = NULL;

    //typedef void* gpointer
    //typedef gulong GType

    //insert at end
    list = g_list_append(list,"this is data1 end");

    //insert at head
    list = g_list_prepend(list,"this is data1 head");

    //insert at 2
    list = g_list_insert(list,"3",2);

    char *second = g_list_nth_data(list,2);
    printf("date 2 is %s\n",second);


    //concat list -> llist
    llist = g_list_copy(list);

    //found the second data
    GList *seconds= g_list_find(list,"3");
    g_print("found the 2 element is %s\n",(gchar *)seconds->data);


    //foreach list before remove
    /*
    while(list!=NULL){
        printf("data is %s\n",list->data);
	list = list->next;
    }
    */

    //remove the second data
    list = g_list_remove(list,"3");

    //get list length
    int length = g_list_length(list);
    printf("length is %d\n",length);

    //reverse list
    list = g_list_reverse(list);


    g_list_foreach(list,each_callback,"user_data");


    printf("---------------------------------------------------------\n");
    //foreach llist
    /*
    while(llist!=NULL){
        printf("llist data is %s\n",llist->data);
	llist = llist->next;
    }
    */
    
    //timer 
    GTimer *timer;
    timer = g_timer_new();
    gulong sec;

    g_timer_start(timer);
    //foreach list
    while(list!=NULL){
        printf("list data is %s\n",list->data);
	list = list->next;
    }
    g_timer_stop(timer);


    g_timer_elapsed(timer,&sec);
    g_print("--use sec is %ld\n",sec);

    g_timer_continue(timer);
    for(int i=0;i<=10000;i++){
        //g_print("%d",i);
    }
   
    g_timer_elapsed(timer,&sec);
    g_print("--- use 10000 sec:is %ld\n",sec);

    //free
    g_list_free(llist);
    g_list_free(list);


    return 0;

}
