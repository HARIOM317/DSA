#include <iostream>

using namespace std;

int getLastBit(int n)
{
    return n & 1;
}

int main()
{
    int n1 = 5, n2 = 8, n3 = 63, n4 = 100;

    cout << "Last bit of n1 = " << getLastBit(n1) << endl;
    cout << "Last bit of n2 = " << getLastBit(n2) << endl;
    cout << "Last bit of n3 = " << getLastBit(n3) << endl;
    cout << "Last bit of n4 = " << getLastBit(n4) << endl;

    return 0;
}