#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
    vector<int> arr;

    // O(log n)
    void heapify(int i) // parent index
    {
        // base case
        if (i >= arr.size())
            return;

        int l = 2 * i + 1; // left child index
        int r = 2 * i + 2; // right child index

        int maxIdx = i;

        if (l < arr.size() && arr[l] > arr[maxIdx])
        {
            maxIdx = l;
        }

        if (r < arr.size() && arr[r] > arr[maxIdx])
        {
            maxIdx = r;
        }

        if (maxIdx != i) // swapping with child node
        {
            swap(arr[i], arr[maxIdx]);
            heapify(maxIdx);
        }
    }

public:
    // O(log n)
    void push(int val)
    {
        // step-1: insert val
        arr.push_back(val);

        // step-2: fix heap
        int x = arr.size() - 1;   // child index
        int parent = (x - 1) / 2; // parent index

        // O(log n) worst case
        while (parent >= 0 && arr[x] > arr[parent])
        {
            swap(arr[x], arr[parent]);
            x = parent;
            parent = (x - 1) / 2;
        }
    }

    // O(log n)
    void pop()
    {
        // step-1: swap root element to last element
        swap(arr[0], arr[arr.size() - 1]);

        // step-2: delete last element
        arr.pop_back();

        // step-3: call heapify for root to fix heap
        heapify(0); // O(log n)
    }

    // O(1)
    int top()
    {
        if (arr.empty())
            return -1;
        return arr[0]; // highest priority element
    }

    // O(1)
    bool empty()
    {
        return arr.size() == 0;
    }

    // O(1)
    int size()
    {
        return arr.size();
    }
};

int main()
{
    MaxHeap pq;

    pq.push(3);
    pq.push(5);
    pq.push(2);
    pq.push(1);
    pq.push(4);

    cout << "Size: " << pq.size() << "\n\n";

    while (!pq.empty())
    {
        cout << "Top: " << pq.top() << endl;
        pq.pop();
    }

    cout << "\nSize: " << pq.size() << endl;

    return 0;
}