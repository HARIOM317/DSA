#include <iostream>

using namespace std;

void printReverseNumbers(int n)
{
    // base case
    if (n == 0)
        return;

    cout << n << " ";
    printReverseNumbers(n - 1);
}

int main()
{
    int n = 15;
    printReverseNumbers(n);

    return 0;
}