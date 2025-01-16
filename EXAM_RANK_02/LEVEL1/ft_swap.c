#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a;
    int *pa;
    int b;
    int *pb;

    a = 1;
    b = 0;
    pa = &a;
    pb = &b;
    printf(" before :\n%d \n %d \n", *pa, *pb);
    ft_swap(pa, pb);
    printf(" after :\n%d \n %d \n", *pa, *pb);

}