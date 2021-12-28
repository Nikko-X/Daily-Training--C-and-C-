#include <stdio.h>
#include<string.h>

/*long int n,num=1,endnum=0,i;
int main(void)
{
    //printf("Pleasr enter the Num \n");
    //scanf("%ld",&n);
    for ( i = 1; i<= 10; i++)
    {
        n = i;
        for( ;n != 0;n--)
        {
            num = num * n;
        }
        endnum = endnum + num;
        num = 1;
    }  printf("The End num is %ld",endnum);
 return 0;
}*/

// 输密码，输入三次失败后退出
/*int i;
char passward[] = "ab1234",input[6];
int main(void)
{
    printf("Please input PassWard-->");
    
    for ( i = 0; i < 3; i++)
    {
        scanf("%s",&input);
        if(strcmp(passward,input) == 0)
        {
            printf("Success !");
            break;
        }
        else if(i !=2 )
        {
            printf("Wrong! Please input again-->");
        }
        else
        {
            printf("Three Times Wrongs !");
        }
    }
    return 0;
}*/

// 按顺序一个一个打印数字
/*void print (int n)
{
    if(n>9)
    {
        print(n/10);        //递归，按顺序打印数字
    }
    printf("%d ",n%10);    //递归完以后最后一次执行，但是参数是最开始传入的
}

int main()
{
    unsigned int num = 0;
    scanf("%d",&num);
    print (num);

    return 0;
}*/

//题目：不用变量，求一个字符的串长度

/*int my_strlen(char* str)
{   
    if(*str != '\0')
    {
        return 1+my_strlen(str+1);
    }
    else
        return 0; 
}

int main()
{
    char arr[] = "123hui";fd
    int len = my_strlen(arr);   //数组传参，传进去的不是数组本身，而是首元素的地址
    printf("len = %d\n",len);
    return 0;
}*/

// 求阶乘
int facl(int n)
{
    if(n>1)
        return n*facl(n-1);
    else
        return 1;
}

int main()
{
    int n = 0,ret = 0;
    scanf("%d",&n);
    ret = facl(n);
    printf("%d\n",ret);
    return 0;
}

