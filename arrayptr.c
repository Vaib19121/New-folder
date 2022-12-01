#include <stdio.h>

/*void printarr(int *arr)
{
    for (int j = 0; j < 5; j++)
    {
        printf("%u %d\n", &arr[j], *(&arr[j]));
    }
}
*/

void array(int *ptr)
{
    printf("%u ", &ptr);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", *(&ptr + i));
    }
}
int main()
{
    int a[5] = {5, 2, 8, 9, 5};
    int *aptr;
    aptr = a;
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d %u %d %u %u\n", i, &i, i[aptr], &aptr[i], &aptr);
    // }

    array(&a[0]);

    return 0;
}