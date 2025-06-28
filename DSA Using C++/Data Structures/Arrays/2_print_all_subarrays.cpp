#include <iostream>

using namespace std;

void printSubArrays(int arr[], int n)
{
    cout << "All subarrays of the array" << endl
         << endl;
    int count = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << count << ". {";
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << (k != j ? "," : "");
            }
            cout << "}" << endl;
            count++;
        }
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    printSubArrays(arr, 5);

    return 0;
}