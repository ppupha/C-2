#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define N_MAX 10
#define EPS 1.0e-7

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
    if (n <= 0 && *n > N_MAX)
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
    printf("\n");
    return;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_index;

    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_index])
            min_index = j;

        swap(&arr[min_index], &arr[i]);
    }
}

int main(void)
{
    int a[N_MAX];
    int n;
    int rc = arrInput(a, &n);
    if (rc == OK)
    {
        printf("Input Array: ");
        arrOutput(a, n);
        selectionSort(a, n);
        printf("Sorted Array: ");
        arrOutput(a, n);
    }

    return rc;
}
