#include <stdio.h>

int arr[10]= {9, 0, 2, 8, 1, 4, 6, 3, 7, 5 };

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void QuickSort(int arr[], int left,int right)
{
    if (left >= right)    //如果左边索引大于或等于右边索引，说明该组序列整理完毕
    {
        return;
    }
    int i = left;
    int j = right;
    int key = arr[i];    //使用key来保存作为键值的数据，将arr[i]空出来
    //本轮排序开始，当i=j时本轮排序结束，将键值赋给arr[i]
    while (i < j)
    {
        while ((i < j)&&(key <= arr[j]))
        {
            //不符合条件，继续向前寻找
            j--;
        }
        //arr[i] = arr[j];//从后往前找到一个小于当前键值的数据arr[j]，将其赋给arr[i]
        swap(&arr[i],&arr[j]);

        //从前往后找一个大于当前键值的数据
        while ((i < j) && (key >= arr[i]))
        {
            //不符合条件，继续向后寻找
            i++;
        }
        //找到或i<j不成立(即序列查找完毕时）while循环结束,进行赋值
        //arr[j] = arr[i];
        swap(&arr[i],&arr[j]);
    }
    arr[i] = key;
    //递归调用排序函数对键值两边的子序列进行排序操作
    QuickSort(arr, left, i - 1);
    QuickSort(arr, i + 1, right);
}


int main(){

    for(int i = 0;i<10;i++){
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    QuickSort(arr,0,9);

    printf("after sort------------------\n");

    for(int i = 0;i<10;i++){
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}
