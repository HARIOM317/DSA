#include <iostream>
#include <string.h>

using namespace std;

int pow(int n, int p)
{
    int power = 1;
    for (int i = 1; i <= p; i++)
    {
        power *= n;
    }

    return power;
}

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
        int lastDigit = n % 2;
        n /= 2;

        binary += (lastDigit == 0 ? "0" : "1");
    }

    binary = reverseString(binary);

    return binary;
}

int main()
{
    cout << pow(3, 3) << endl;

    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    cout << "Binary = " << decimalToBinary(decimal) << endl;

    return 0;
}