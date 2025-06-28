#include <iostream>

using namespace std;

// Method 1
int changeBit(int num, int i, int bit)
{
    if (bit == 1)
    {
        // set ith bit
        int mask = 1 << i;
        return num | mask;
    }
    else
    {
        // clear ith bit
        int mask = ~(1 << i);
        return num & mask;
    }
}

// Method 2
int updateBit(int num, int i, int bit)
{
    num = num & ~(1 << i);
    num = num | (bit << i);
    return num;
}

int main()
{
    int num = 7, i = 3, bit = 1; // 000111 --> 001111 = 15
    cout << "Change Bit = " << changeBit(num, i, bit) << endl;
    cout << "Update Bit = " << updateBit(num, i, bit) << endl;

    num = 7, i = 2, bit = 0; // 000111 --> 000011 = 3
    cout << "\nChange Bit = " << changeBit(num, i, bit) << endl;
    cout << "Update Bit = " << updateBit(num, i, bit) << endl;

    return 0;
}