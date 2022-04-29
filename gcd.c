// Write a program to find gcd recursively
#include <stdio.h>

int gcd(int n, int m)
{
    if (m == 0)
		return n;
	else
		return gcd(m, n % m);
}

void main()
{

    // c code to check gcd
    int n, m;
    printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);
    printf("GCD of %d and %d is %d", n, m, gcd(n, m)); 
}