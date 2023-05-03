#include <bits/stdc++.h>

using namespace std;

int divisible(int n, int a, int b)
{
    int c1 = n / a;
    int c2 = n / b;
    int c3 = n / (a * b);

    return ((c1 + c2) - c3);
}

int main()
{
    // Approach - how many numbers between 1 to 1000 are divisible by 5 and 7?
    // Principle =  (numbers divisible by 5 + numbers divisible by 7) - numbers divisible by both.
    int n, a, b;
    cout << "Enter value of n, a and b \n";
    cin >> n >> a >> b;

    cout << divisible(n, a, b) << " numbers found which are divided by " << a << " and " << b << endl;

    return 0;
}