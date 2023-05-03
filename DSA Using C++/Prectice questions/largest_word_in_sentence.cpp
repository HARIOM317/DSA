#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter size of word : ";
    cin >> n;
    cin.ignore();
    char arr[n + 1];
    cout << "Enter word : ";
    cin.getline(arr, n);
    cin.ignore();

    int i = 0;
    int currLength = 0;
    int maxLength = 0;

    int start = 0, max_st = 0;
    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLength > maxLength)
            {
                maxLength = currLength;
                max_st = start;
            }
            currLength = 0;
            start = i + 1;
        }
        else
        {
            currLength++;
        }
        if (arr[i] == '\0')
        {
            break;
        }
        i++;
    }

    cout << "Max word length is : " << maxLength << endl;

    cout << "and that word is : ";
    for (int i = 0; i < maxLength; i++)
    {
        cout << arr[i + max_st];
    }

    return 0;
}