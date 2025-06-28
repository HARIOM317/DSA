#include <iostream>

using namespace std;

/*
    let num = 15, n = 3

    0        -->   0000...0000
    ~0       -->   111.....111
    ~0 << n  -->   111...11000

    Hence, num & (~0 << n) --> to clear last n bits

    num = 15         --->  ...00001111
    ~0 << n          --->  ...11111000
    num & (~0 << n)  --->  ...00001000

    Output = 8
*/

int clearLastNBits(int num, int n)
{
    return num & (~0 << n);
}

int main()
{
    int num = 15, n = 3;
    cout << "Output = " << clearLastNBits(num, n) << endl;

    return 0;
}