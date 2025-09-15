#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // step-1 : Build heap using heapify
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // step-2 : Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);

        // call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {9, 4, 3, 8, 10, 2, 5};

    heapSort(arr);
    print(arr);

    return 0;
}