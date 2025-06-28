#include <iostream>

using namespace std;

int main()
{
    int a = 7;  // 000....00000111
    int x = ~a; // -7
    /*
        ~7 = (sign bit) 1, (magnitude)11....111111000
        step-1: check sign bit = 1 (-ve number)
        step-2: 1's compliment of magnitude (00....000000111)
        step-3: 2's compliment of number (00....000000111 + 00....0001) = 000...0001000 = 8

        That's why ~7 = -8
    */

    cout << "a = " << a << endl;
    cout << "x = " << x << endl;

    return 0;
}