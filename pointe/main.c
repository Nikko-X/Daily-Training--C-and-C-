#include <stdio.h>

int my_strlen(char * str)
{
    char* start = str;
    char* end = str;
    while (*end != '\0')    // 加* 表示所指向的元素
    {
        end ++;         // 调用的时候 不加* 号表示的是地址
    }
    return end - start;
}
int main()
{
    /*2021/12/29/指针类型
    
    printf("%d\n",sizeof(char *));
    printf("%d\n",sizeof(short*));
    printf("%d\n",sizeof(int*));
    printf("%d\n",sizeof(int*));
    printf("%d\n",sizeof(double*));*/
    //64位系统，指针的大小都是8个字节

    /*int a = 0X11223344;     //16位2个数占用一个字节 所以可以放的下
    int *pa = &a;  //将地址放入整型指针 pa 中
    *pa = 0;       //通过指针修改变量 a 的值 ----》结果全部修改为0了
    */


    /*int a = 0x1122334455667788;
    char *pa = &a;
    *pa = 0;  // 此时的结果----》 只修改了最后2个 改为了0  所以指针分类型是有意义的
    */
   //利用指针实现 求字符串长度函数功能 strlen
    char arr[] = {"hello"};
    int len = my_strlen(arr);
    printf("%d\n",len);
    return 0;
}