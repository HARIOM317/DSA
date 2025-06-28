#include <iostream>

using namespace std;

void printAllSubarrays(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        string subArr = "";
        for (int j = i; j < n; j++)
        {
            subArr += to_string(arr[j]) + " ";
            cout << subArr << endl;
        }
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printAllSubarrays(arr, 5);

    return 0;
}