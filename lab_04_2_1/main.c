#include <stdio.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define N_MAX  10
#define ERR_COUNT 3

/*
Function for input a array
a - array
n - range of array (pointer)
*/
int arrInput(int *a, int *n)
{
    printf("Input Range of Array: ");
    if (scanf("%d", n) != 1)
    {
        printf("IO Range\n");
        return ERR_IO;
    }
    if (n <= 0 && *n > N_MAX)
    {
        printf("Range Error\n");
        return ERR_RANGE;
    }
    for (int i = 0; i < *n; i++)
    {
        if (scanf("%d", &a[i]) == 0)
        {
            printf("IO Error\n");
            return ERR_IO;
        }
    }
    return OK;
}

int main(void)
{
    int a[N_MAX];
    int n;
    int count = 0, s = 0;
    float re;
    int rc = arrInput(a, &n) != 0;
    if (rc == OK)
    {
        for (int i =0; i < n; i++)
        if (a[i] < 0)
        {
            count ++;
            s = s + a[i];
        }
        if (count == 0)
        {
            printf("Count Error\n");
            rc = ERR_COUNT;
        }
        else
        {
            re = 1.0 * s / count;
            printf("Result is %8.5f\n", re);
        }
    }
    return rc;
}
