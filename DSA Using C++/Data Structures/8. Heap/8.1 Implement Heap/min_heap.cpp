#include <iostream>
#include <vector>

using namespace std;

class MinHeap
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

        int minIdx = i;

        if (l < arr.size() && arr[l] < arr[minIdx])
        {
            minIdx = l;
        }

        if (r < arr.size() && arr[r] < arr[minIdx])
        {
            minIdx = r;
        }

        if (minIdx != i) // swapping with child node
        {
            swap(arr[i], arr[minIdx]);
            heapify(minIdx);
        }
    }

public:
    // O(log n)
    void push(int val)
    {
        // step-1: insert element
        arr.push_back(val);

        // step-2: fix heap
        int x = arr.size() - 1;   // child index
        int parent = (x - 1) / 2; // parent index

        while (parent >= 0 && arr[x] < arr[parent]) // O(log n)
        {
            swap(arr[x], arr[parent]);
            x = parent;
            parent = (x - 1) / 2;
        }
    }

    // O(log n)
    void pop()
    {
        // step-1: swap root with last element
        swap(arr[0], arr[arr.size() - 1]);

        // step-2: remove last element
        arr.pop_back();

        // step-3: call heapify for root to fix heap
        heapify(0); // O(log n)
    }

    // O(1)
    int top()
    {
        if (arr.empty())
            return -1;
        return arr[0]; // minimum priority element
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
    MinHeap pq;

    pq.push(3);
    pq.push(4);
    pq.push(1);
    pq.push(2);
    pq.push(5);

    cout << "Size: " << pq.size() << "\n\n";

    while (!pq.empty())
    {
        cout << "Top: " << pq.top() << endl;
        pq.pop();
    }

    cout << "\nSize: " << pq.size() << endl;

    return 0;
}