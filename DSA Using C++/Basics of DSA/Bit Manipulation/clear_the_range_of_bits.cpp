#include <iostream>

using namespace std;

int clearRangeOfBits(int num, int i, int j)
{
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;

    int mask = a | b;
    return num & mask;
}

int main()
{
    int num = 30; // 11110 --> 10000 = 16
    int i = 1, j = 3;

    cout << "Output = " << clearRangeOfBits(num, i, j) << endl;

    num = 63; // 111111 --> 100011 = 35
    i = 2, j = 4;

    cout << "Output = " << clearRangeOfBits(num, i, j) << endl;

    return 0;
}