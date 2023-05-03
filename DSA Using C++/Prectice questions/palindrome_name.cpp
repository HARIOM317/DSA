#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter size of word : ";
    cin >> n;

    char arr[n + 1];
    cout << "Enter word : ";
    cin >> arr;

    bool check = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n - 1 - i])
        {
            check = 0;
        }
    }

    if (check)
    {
        cout << "Word is palindrome.";
    }
    else
    {
        cout << "Word is not palindrome.";
    }

    return 0;
}