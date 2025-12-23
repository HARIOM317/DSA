#include <iostream>
#include <vector>

using namespace std;

// need to pass reference of a nad b to reflect changes in original
void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// bubble sort algorithm [Time complexity: O(n^2)]
void bubbleSort(vector<int> arr) // passing by value to not reflect changes in original array
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool isSwap = false; // to track that array is already sorted or not
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // for decreasing order (arr[j] < arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap)
        {
            break;
        }
    }

    // printing array
    cout << "After bubble sort: \t";
    printArray(arr);
}

// selection sort [Time complexity: O(n^2)]
void selectionSort(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[i]) // for decreasing order (arr[j] > arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    // printing array
    cout << "After selection sort: \t";
    printArray(arr);
}

// insertion sort [Time complexity: O(n^2)]
void insertionSort(vector<int> arr)
{
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int current = arr[i], prev = i - 1;
        while (prev >= 0 && arr[prev] > current) // for decreasing order (arr[j] < current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
        count++;
        cout << "Count: " << count << endl;
    }

    // printing array
    cout << "After insertion sort: \t";
    printArray(arr);
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nGiven array is: \t";
    printArray(arr);

    // after bubble sort
    bubbleSort(arr);
    selectionSort(arr);
    insertionSort(arr);

    return 0;
}