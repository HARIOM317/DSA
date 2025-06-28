#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * 1 + 2;

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

void buildHeap(vector<int> &arr, int n)
{
    // start from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void printHeap(const vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {20, 30, 40, 50, 10, 35, 15, 45, 2, 3};
    int n = arr.size();

    cout << "Original array : ";
    printHeap(arr);

    // build a max heap
    buildHeap(arr, n);

    cout << "Heapified array (Max-Heap) : ";
    printHeap(arr);

    return 0;
}