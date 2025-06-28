#include <iostream>

using namespace std;

int clearIthBit1(int num, int i)
{
    int mask = num & (1 << i);
    return num ^ mask;
}

int clearIthBit2(int num, int i)
{
    int mask = ~(1 << i);
    return num & mask;
}

int main()
{
    int num = 6, i = 1;
    cout << "After clear bit by F1 : " << clearIthBit1(num, i) << endl;
    cout << "After clear bit by F2 : " << clearIthBit2(num, i) << endl;

    return 0;
}