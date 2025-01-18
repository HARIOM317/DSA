#include <iostream>

using namespace std;

// Sum of first n even numbers
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    int evenSum = 0;
    for (int i = 0, j = 0; i < n; i ++, j+=2)
    {
        evenSum += j;
    }

    cout << "Sum = " << evenSum << endl;

    return 0;
}