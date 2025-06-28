#include <iostream>

using namespace std;

int decimalToBinary(int decimal)
{
    int binary = 0, pow = 1;
    while (decimal > 0)
    {
        int remainder = decimal % 2;
        decimal = decimal / 2;
        binary += (remainder * pow);
        pow *= 10;
    }

    return binary;
}

int binaryToDecimal(int binary)
{
    int decimal = 0, pow = 1;
    while (binary > 0)
    {
        int remainder = binary % 10;
        binary = binary / 10;
        decimal += (remainder * pow);
        pow *= 2;
    }

    return decimal;
}

int main()
{
    int decimal = 50, binary = 110010;
    cout << decimalToBinary(decimal) << endl;
    cout << binaryToDecimal(binary) << endl;

    return 0;
}