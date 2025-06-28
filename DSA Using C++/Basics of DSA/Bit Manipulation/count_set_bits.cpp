#include <iostream>

using namespace std;

int getSetBits(int n)
{
    int totalSetBits = 0;
    while (n != 0)
    {
        // step-1 : extract last bit and add in totalSetBits
        totalSetBits += (n & 1);

        // step-2 : right shift number by 1
        n = n >> 1;
    }
    return totalSetBits;
}

int main()
{
    int num1 = 10; // 1010
    int num2 = 15; // 1111

    cout << "Total set bits in " << num1 << " = " << getSetBits(num1) << endl;
    cout << "Total set bits in " << num2 << " = " << getSetBits(num2) << endl;

    return 0;
}