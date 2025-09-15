#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // __________ MAX HEAP __________
    priority_queue<int> maxHeap;

    maxHeap.push(4);
    maxHeap.push(1);
    maxHeap.push(3);
    maxHeap.push(5);
    maxHeap.push(2);

    cout << "Max Heap Size: " << maxHeap.size() << endl;
    cout << "Max Heap Data: " << endl;
    while (!maxHeap.empty())
    {
        cout << "Top: " << maxHeap.top() << endl;
        maxHeap.pop();
    }

    // __________ MIN HEAP __________
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(2);

    cout << "\nMin Heap Data: " << endl;
    while (!minHeap.empty())
    {
        cout << "Top: " << minHeap.top() << endl;
        minHeap.pop();
    }

    return 0;
}