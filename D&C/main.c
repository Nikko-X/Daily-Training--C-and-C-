#include <stdio.h>

int sumnum = 0,size = 0 ;     //用了许多的全局变量，或许该思考一下应该如何优化

int sum(int arr[])
{
    
    if(size >= 0 )
    {
        sumnum += arr[size];
        size --;
        sum(arr);       //利用 递归 求数组里面数据的和
    }
    return sumnum;
}

int main()
{
    int arr1[] = {7,2,9,4,5,6,7},endsum;
    size = (sizeof (arr1) / sizeof (arr1[0])) - 1;
    endsum = sum(arr1);
    printf("The sum is %d\n",endsum);
    return 0;
}