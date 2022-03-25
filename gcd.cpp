// Write a program to find gcd recursively
#include <iostream>
#include <conio.h>
using namespace std;

int gcd(int n, int m)
{
    if (m == 0)
		return n;
	else
		return gcd(m, n % m);
}

int main()
{
    cout<< endl << gcd(42, 56); // 14
    cout<< endl << gcd(461952, 116298); // 18
    cout<< endl << gcd(7966496, 314080416) ; // 32
    cout<< endl << gcd(24826148, 45296490); // 526
    cout<< endl << gcd(12, 0) ; // 12
    cout<< endl << gcd(0, 0); // 0
    cout<< endl << gcd(0, 9); // 9
    return 0;
}