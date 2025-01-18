#include <iostream>
#include <string>

using namespace std;

void replaceSpaces(string &str)
{
    int spaceCount = 0, n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
            spaceCount++;
    }

    int newLength = n + spaceCount * 2;
    str.resize(newLength);
    int i = n - 1, j = newLength - 1;
    while (i >= 0)
    {
        if (str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '4';
            str[j--] = '@';
        }
        else
        {
            str[j--] = str[i];
        }
        i--;
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    replaceSpaces(str);
    cout << "New string is: " << str << endl;

    return 0;
}