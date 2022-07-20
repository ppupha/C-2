#include <stdio.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define NMAX 10
#define ERR_COUNT 3;

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
        printf("IO Range");
        return ERR_IO;
    }
    if (n <= 0 && *n > NMAX)
    {
        printf("Range Error");
        return ERR_RANGE;
    }
    for (int i = 0; i < *n; i++)
    {
        if (scanf("%d", &a[i]) == 0)
        {
            printf("IO Error");
            return ERR_IO;
        }
    }
    return OK;
}

/*
Function for output array
a - array
n - range of array
*/
void arrOutput(const int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return;
}

/*
Function for checking an integer starts and ends with a digit
n - an integer
*/
int check(int n)
{
    int e;
    e = n % 10;
    while (n > 10)
        n /= 10;
    return (n == e);
}

/*
Function for creating a array from elements start and end with a digit
a - input array
na - range of array a
b - return array
nb - range of array b (a pointer)
*/
void arrMake(int *a, int na, int *b, int *nb)
{
    *nb = 0;
    for (int i = 0; i < na; i ++)
    {
        if (check(a[i]))
        {
            b[*nb] = a[i];
            *nb = *nb +1;
        }
    }
    return;
}

int main(void)
{
    int a[NMAX], b[NMAX];
    int na, nb;
    int rc = arrInput(a, &na);
    if (rc == OK)
    {
        arrMake(a, na, b, &nb);
        if (nb == 0)
        {
            printf("Count Error\n");
            rc = ERR_COUNT;
        }
        else
            arrOutput(b, nb);
    }
    return rc;
}
