#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    int count3 = 0, count5 = 0;

    for (int i = 1; i <= n; i++)
    {
        count3++;
        count5++;

        if (count3 == 3 && count5 == 5)
        {
            cout << "Fizz Buzz" << endl;
            count3 = count5 = 0;
        }
        else if (count3 == 3)
        {
            cout << "Fizz" << endl;
            count3 = 0;
        }
        else if (count5 == 5)
        {
            cout << "Buzz" << endl;
            count5 = 0;
        }
        else
        {
            cout << i << endl;
        }
    }

    return 0;
}