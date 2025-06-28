#include <iostream>

using namespace std;

int main()
{
    int a = 7; // 111
    int b = 2; // 010

    cout << "Bitwise AND : " << (a & b) << endl;          // 010 = 2
    cout << "Bitwise OR : " << (a | b) << endl;           // 111 = 7
    cout << "Bitwise XOR : " << (a ^ b) << endl;          // 101 = 5
    cout << "Bitwise LEFT SHIFT : " << (a << b) << endl;  // 11100 = 28
    cout << "Bitwise RIGHT SHIFT : " << (a >> b) << endl; // 001 = 1

    return 0;
}