// recursive fibbonacci 
#include <stdio.h>
int fibbonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibbonacci(n - 1) + fibbonacci(n - 2);
}

void main()
{
    //  Testing fibbonacci
    for (int i=0; i<=10; i++)
        printf("%d ", fibbonacci(i));
    
}