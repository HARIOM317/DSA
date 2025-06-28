#include <iostream>

using namespace std;

string checkOddEven(int n)
{
    if (n & 1) // getting last bit (1 --> odd, 0 --> even)
        return "Odd Number";
    else
        return "Even NUmber";
}

int main()
{
    int n1 = 8, n2 = 11;

    cout << checkOddEven(n1) << endl;
    cout << checkOddEven(n2) << endl;

    return 0;
}