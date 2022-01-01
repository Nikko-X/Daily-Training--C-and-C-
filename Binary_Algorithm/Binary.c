/* 利用二分法找出数组里面想要的数字，该数组必须是大小按顺序排列的 */

#include <stdio.h>
#include <string.h>
int main()
{
    int low = 0,high,mid,guess;
    int str[20] = {1,2,6,9,10,17,20,21,23,26,27,28,29,32,34,37,39,40,41,44};

    high = (sizeof(str) / sizeof(str[0])) - 1;        //这里求数组长度，求总长度时必须用 str 不可以用str[]会报错 也不可用str[20],这样求出的是一位的长度 ！！
    mid = (high + low) / 2;
    printf("Please input num you want to fine-->");
    scanf("%d",&guess);
    while(low <= high)              //只要中间还有数字 就需要比较，当最小大于最大时就结束循环
    {
        if(str[mid] > guess)
        {
            high = mid - 1;
        }
        else if(str[mid] < guess)
        {
            low = mid + 1;
        }   
        else if(str[mid] == guess)
        {
            printf("The %d at str[%d]",guess,mid);
            break;
        }

        if(low > high)         // 配合while循环 打出未找到
        {
            printf("None !");
        }
        mid = (high + low) / 2;

    }
    
    return 0;
}