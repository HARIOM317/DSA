#include <iostream>
#include <limits.h>

using namespace std;

// Time: O(log n), Space: O(long n)
void decToBinRec(int d, string &res)
{
    if (d > 1)
    {
        decToBinRec(d / 2, res);
    }
    res += (d % 2) + '0';
}

string decimalToBinary(int decimal)
{
    string result = "";
    decToBinRec(decimal, result);
    return result;
}

int main()
{
    int d = INT_MAX; // 2147483647 = 1111111111111111111111111111111

    cout << "Binary(" << d << ") = " << decimalToBinary(d) << endl;

    return 0;
}