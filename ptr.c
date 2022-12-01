#include <stdio.h>
int main()
{
    /* int *ptr1,*ptr2;
     int a,b;
     scanf("%d",&a);
    scanf("%d",&b);
     ptr1 = &a;
     printf("%d %d\n",*ptr1,&a);
     ptr1=&b;
     printf("%d %d",*ptr1,&b);
    */

    char *ptr;
    char a = 'a';
    ptr = &a; // ptr->a
    for (int i = 1; i < 20; i++)
    {
        printf("%u %c \n", ptr, *ptr);
        ptr--;
    }

    return 0;
}