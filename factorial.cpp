#include <iostream>
#include <conio.h>
using namespace std;

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n*fact(n-1);
}

int main()
{
    cout<<"Factorial : Enter the number : ";
    int n;
    cin >> n;
    cout<<"Factorial of "<< n << " is "<< fact(n);
    return 0;
}