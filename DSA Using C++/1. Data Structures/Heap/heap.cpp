#include <iostream>

using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteNode()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }

        // step-1 : insert last element at the root
        arr[1] = arr[size];

        // step-2 : delete the last element
        size--;

        // step-3: propagate root node to its correct position
        int index = 1;
        while (index <= size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largest = index;

            if (leftIndex <= size && arr[largest] < arr[leftIndex])
            {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[largest] < arr[rightIndex])
            {
                largest = rightIndex;
            }

            if (largest != index)
            {
                swap(arr[largest], arr[index]);
                index = largest;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h;

    // insertion
    h.insert(50);
    h.insert(30);
    h.insert(60);
    h.insert(40);
    h.insert(70);
    h.insert(10);
    h.insert(20);
    h.insert(80);
    h.insert(90);
    h.insert(100);

    // deletion
    h.deleteNode();
    h.deleteNode();
    h.deleteNode();
    h.deleteNode();
    h.deleteNode();

    h.print();

    return 0;
}