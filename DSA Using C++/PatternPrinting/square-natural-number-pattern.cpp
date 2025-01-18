#include <iostream>

using namespace std;

// Square of number starts from 1 to count
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    int count = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", count);
            count++;
        }
        cout << endl;
    }

    return 0;
}