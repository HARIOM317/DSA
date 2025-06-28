#include <iostream>

using namespace std;

/*
    n = 2 --> (0010) & (n-1) --> (0001) = 0000
    n = 4 --> (0100) & (n-1) --> (0011) = 0000
    n = 8 --> (1000) & (n-1) --> (0111) = 0000
*/

string isPowerOf2(int n)
{
    int mask = n & (n - 1);
    return mask == 0 ? "Yes" : "No";
}

int main()
{
    int n1 = 2, n2 = 8, n3 = 128;
    int p1 = 7, p2 = 25, p3 = 100;

    cout << n1 << " is power of 2 = " << isPowerOf2(n1) << endl;
    cout << n2 << " is power of 2 = " << isPowerOf2(n2) << endl;
    cout << n3 << " is power of 2 = " << isPowerOf2(n3) << "\n\n";

    cout << p1 << " is power of 2 = " << isPowerOf2(p1) << endl;
    cout << p2 << " is power of 2 = " << isPowerOf2(p2) << endl;
    cout << p3 << " is power of 2 = " << isPowerOf2(p3) << endl;

    return 0;
}