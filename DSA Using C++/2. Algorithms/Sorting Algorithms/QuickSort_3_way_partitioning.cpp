#include <iostream>

using namespace std;

void TWP(int arr[], int m, int n, int &begin, int &end)
{
    int pivot = arr[m];
    begin = m;
    end = n;

    for (int i = begin + 1; i <= end; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[begin]);
            begin++;
        }
        else if (arr[i] > pivot)
        {
            swap(arr[i], arr[end]);
            end--;
            i--;
        }
    }
}

void quicksort(int arr[], int m, int n)
{
    if (m >= n)
    {
        return;
    }
    int begin, end;
    TWP(arr, m, n, begin, end);
    quicksort(arr, m, --begin);
    quicksort(arr, ++end, n);
}

int main()
{
    int arr[15] = {12, 87, 90, 15, 55, 3, 9, 7, 1, 4, 0, 2, 6, 5, 11};
    int n = 15;
    quicksort(arr, 0, n - 1);

    cout << "Sorted array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}