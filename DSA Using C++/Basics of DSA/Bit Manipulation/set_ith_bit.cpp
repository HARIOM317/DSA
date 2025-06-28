#include <iostream>

using namespace std;

int setIthBit(int n, int i)
{
    int bitMask = 1 << i; // (left shift 1 by i)
    return n | bitMask;
}
int main()
{
    int n = 6, i = 3;

    cout << "Output = " << setIthBit(n, i) << endl;

    return 0;
}