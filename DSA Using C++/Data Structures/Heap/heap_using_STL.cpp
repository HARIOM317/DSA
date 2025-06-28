#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // creating max heap
    priority_queue<int> maxHeap;

    maxHeap.push(20);
    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(40);

    cout << "Max Heap : ";
    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    // creating min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(20);
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(50);
    minHeap.push(40);

    cout << "\nMin Heap : ";
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}