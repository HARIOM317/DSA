#include <iostream>

using namespace std;


// Printing character type according to its ASCII value
int main()
{
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if (ch >= 65 && ch <= 90)
    {
        cout << "This is Uppercase Character" << endl;
    }
    else if (ch >= 91 && ch <= 122)
    {
        cout << "This is Lowercase Character" << endl;
    }
    else if (ch >= 48 && ch <= 57)
    {
        cout << "This is Number" << endl;
    }
    else
    {
        cout << "This is Special Character" << endl;
    }
    return 0;
}