#include <iostream>
#include <string.h>

using namespace std;

string reverseString(string str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    return str;
}

string decimalToBinary(int n)
{
    string binary = "";
    if (n == 0)
    {
        return "0";
    }

    while (n > 0)
    {
        int rem = n % 2;
        n = n >> 1; // n /= 2

        binary += (rem == 0 ? "0" : "1");
    }

    binary = reverseString(binary);

    return binary;
}

int main()
{
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    cout << "Binary = " << decimalToBinary(decimal) << endl;

    return 0;
}