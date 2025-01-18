#include <iostream>
#include <vector>

using namespace std;

// to print first n prime numbers
void primeSieve(int n)
{
    if (n < 2)
    {
        cout << "No prime numbers" << endl;
        return;
    }
    vector<bool> prime(n, true); // creating n size of vector with marking all element as prime true
    prime[0] = prime[1] = false;

    cout << "\nPrime numbers are: ";
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false; // marking multiple of i as false
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    primeSieve(n);

    return 0;
}