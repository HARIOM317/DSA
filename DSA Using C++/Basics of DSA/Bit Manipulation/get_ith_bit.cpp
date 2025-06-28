#include <iostream>

using namespace std;

int getIthBit(int n, int i)
{
    return (n >> i) & 1;
}

int main()
{
    int num = 10, i = 3;
    cout << i << "th bit of " << num << " = " << getIthBit(num, i) << endl;

    return 0;
}