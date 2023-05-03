#include <bits/stdc++.h>

using namespace std;

void primeSieve(int n)
{
    int prime[1000] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    // Find prime number using sieve of eratosthenes approach

    // Principle - start from 2 and mark all the multiples of 2 and move on 3 and mark all the multiple of 3 and so on.
    // Foe every number start marking from that's square, ex- for 2 start from 4, for 3 start from 9, ..., for 7 start from 49 and so on.

    int n;
    cout << "Enter number : ";
    cin >> n;

    primeSieve(n);

    return 0;
}