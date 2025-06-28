#include <iostream>

using namespace std;

bool isPalindrome(int n)
{
    int num = n, reverseNum = 0;
    while (num != 0)
    {
        int lastDigit = num % 10;
        num /= 10;
        reverseNum = reverseNum * 10 + lastDigit;
    }
    return reverseNum == n;
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    cout << "Palindrome : " << (isPalindrome(n) ? "Yes" : "No") << endl;

    return 0;
}