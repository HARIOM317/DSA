#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string b1, string b2)
{
    string result = "";
    int i = b1.length() - 1, j = b2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        // convert char int int
        if (i >= 0)
            sum += b1[i--] - '0';
        if (j >= 0)
            sum += b2[j--] - '0';

        result += (sum % 2) + '0';
        carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string b1, b2;
    cout << "Enter two binary numbers : ";
    cin >> b1 >> b2;

    cout << "Sum = " << addBinary(b1, b2) << endl;

    return 0;
}