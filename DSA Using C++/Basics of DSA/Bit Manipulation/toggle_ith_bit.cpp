#include <iostream>

using namespace std;

int toggleIthBit(int num, int i)
{
    return num ^ (1 << i);
}

int main()
{
    int num = 15, i = 2; // 1111 ---> 1011 = 11
    cout << "Output : " << toggleIthBit(num, i) << endl;

    return 0;
}