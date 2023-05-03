#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "bigboSShgdfdHSRhdgfdhgfGFFFDGHGJHGjjhjh";

    // Convert into upper case
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }

    cout << "Uppercase string is :" << str << endl;

    // Convert into lower case
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }

    cout << "Lowercase string is :" << str << endl;

    return 0;
}