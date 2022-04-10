#include <stdio.h>
#include <malloc.h>
int main()
{
    int n;
    int max;
    int* p;
    scanf("%d",&max);
    p = (int*)malloc(max*sizeof(int));

    for(n = 0; n < max; n++)
    {
        scanf("%d",p);
        p++;
    }
    p = p - max;
    for(n = 0; n < max; n++)
    {
        printf("%d",*p);
        p++;
    }
    return 0;
}