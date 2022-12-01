#include <stdio.h>

void changebyvalue(int a)
{
    a = a * 2;
}

void changebyref(int *a)
{
    *a = *a * 3;
}
int main()
{
    /*int a = 5, b = 6;
    int *ptr;
    int **aptrptr;
    ptr = &a;
    aptrptr = &ptr;
    printf("%d \n", a);
    printf("%u \n", &a);
    printf("%d \n", ptr);
    printf("%u \n", &ptr);
    printf("%d \n", *ptr);
    printf("%d \n", aptrptr);
    printf("%u \n", &aptrptr);
    printf("%d \n", *aptrptr);
    printf("%d", **aptrptr);
    */

    int a = 5, b = 6, temp;
    int *ptr;
    int **aptrptr;
    ptr = &a;
    aptrptr = &ptr;
    // **aptrptr = 10;
    // *aptrptr = &a;
    // **aptrptr = 20;
    temp = **aptrptr;
    **aptrptr = b;
    *aptrptr = &b;
    **aptrptr = temp;
    printf("value of a is %d and valeof b is %d ", a, b);

    /*
        int a = 5;
        changebyvalue(a);
        printf("change by value : %d", a);
        changebyref(&a);
        printf("change by value : %d", a);
    */
    return 0;
}