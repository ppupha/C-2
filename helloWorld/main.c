#include <stdio.h>
#include <stdlib.h>

#define ten 'a'
void tong(int n);
int main()
{
    int a = 1;
    int b = 2;
    int c = 4;
    //printf("%d\n",tong(a, b));
    //printf("%d\n",a);
    tong(10);
    return 0;
    //kbgjbkjfnfgkf

}
void tong(int n)
{
    int count = 10;
    printf("%d",count);
    for (int i = 0; i < n; i++) {
        int count = 1;
        printf("%d ", count );
    }
    printf("\n%d ", count);
    return;
}
