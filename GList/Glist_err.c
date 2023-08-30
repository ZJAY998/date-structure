#include <stdio.h>
#include <glib.h>

const char * str = "test for g_strdup";


int main(){

    gchar *strdup = g_strdup(str);
    
    if(NULL!=strdup){
        printf("strdup is %s\n",strdup);    
	free(strdup);
	strdup = NULL;
    }


    int err_num = 998;
    gchar *str_error = g_strerror(err_num);
    if(NULL!=str_error){
        printf("str_error is %s\n",str_error);    
	free(str_error);
	str_error = NULL;
    }


    //gerror  print   
    //g_error("this is g_error ...");//exit


    g_warning("this is g_warning ...");
    g_message("this is g_message ...");
    g_print("this is g_error ...");


    return 0;
}
