#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void sieve(vector<long long> &prime, int n)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            for (long long j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void segmentSieve(int l, int h)
{
    vector<long long> prime; // to tores all prime numbers up to sqrt(h)
    long long sq = sqrt(h);
    sieve(prime, sq);

    vector<bool> isPrime(h - l + 1, true);

    for (long long p : prime)
    {
        long long sm = max(p * p, (l / p) * p);
        if (sm < l)
            sm += p;

        for (long long i = sm; i <= h; i += p)
        {
            isPrime[i - l] = false;
        }
    }

    // printing prime numbers
    cout << "\nPrime numbers between " << l << " and " << h << " are: ";
    for (long long i = l; i <= h; i++)
    {
        if (isPrime[i - l] && i >= 2)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int l, h;
    cout << "Enter low and high value: ";
    cin >> l >> h;

    segmentSieve(l, h);

    return 0;
}