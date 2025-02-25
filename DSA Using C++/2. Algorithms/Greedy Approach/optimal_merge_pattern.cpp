#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Minimize the cost to merge multiple files by always merging the two smallest files first (using a min-heap).

int minCost(vector<int> &files, int n)
{
    // create min-heap with file sizes
    priority_queue<int, vector<int>, greater<int>> minHeap(files.begin(), files.end());

    int totalCost = 0;
    while (minHeap.size() > 1)
    {
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int sum = first + second;
        totalCost += sum;

        minHeap.push(sum);
    }

    return totalCost;
}

int main()
{
    // No of files
    int n = 6;

    // 6 files with their sizes
    vector<int> files = {2, 3, 4, 5, 6, 7};

    // Total no of computations do be done final answer
    cout << "Minimum Computations = " << minCost(files, n) << endl;

    return 0;
}