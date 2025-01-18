#include <iostream>

using namespace std;

int binaryToDecimal(string str)
{
    int decimal = 0, pow = 1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        int lastDigit = str[i] - '0';
        decimal += (lastDigit * pow);
        pow = pow << 1; // pow *= 2
    }

    return decimal;
}

int main()
{
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    cout << "Decimal = " << binaryToDecimal(binary) << endl;

    return 0;
}