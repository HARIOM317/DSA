#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree; // stores the segment tree
    int n;            // size of the input array

    // Utility function to build segment tree
    void build(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);   // build left child
            build(arr, 2 * node + 2, mid + 1, end); // build right child

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // combine
        }
    }

    // Utility function to query the sum in range [l, r]
    int query(int node, int start, int end, int l, int r)
    {
        // No overlap condition: current segment is completely outside the query range.
        if (end < l || start > r)
            return 0;

        // Total overlap condition: current segment is completely inside the query range.
        if (l <= start && r >= end)
            return tree[node];

        // Partial overlap: query both halves.
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) +
               query(2 * node + 2, mid + 1, end, l, r);
    }

    // Utility function to update a value and propagate change
    void update(int node, int start, int end, int index, int value)
    {
        if (start == end)
        {
            tree[node] = value; // leaf node
        }
        else
        {
            int mid = (start + end) / 2;

            if (index <= mid)
            {
                update(2 * node + 1, start, mid, index, value); // update left child
            }
            else
            {
                update(2 * node + 2, mid + 1, end, index, value); // update right child
            }

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // update parent
        }
    }

    // Recursive helper function to print only the used nodes of the segment tree.
    void printUtil(int node, int start, int end)
    {
        cout << "Node index " << node << " (range [" << start << ", " << end << "]) : " << tree[node] << endl;

        if (start != end)
        { // if not a leaf node, traverse children
            int mid = (start + end) / 2;
            printUtil(2 * node + 1, start, mid);
            printUtil(2 * node + 2, mid + 1, end);
        }
    }

public:
    // Constructor: builds the segment tree from the input array
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);      // allocate memory (safe size)
        build(arr, 0, 0, n - 1); // start building from root node (node 0)
    }

    // Public method for range sum query
    int rangeSum(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    // Public method to update a value at a given index
    void updateValue(int index, int newValue)
    {
        update(0, 0, n - 1, index, newValue);
    }

    // Public method to print only the nodes used in the segment tree.
    void print()
    {
        cout << "\nSegment Tree (used nodes only):" << endl;
        printUtil(0, 0, n - 1);
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {1, 14, 5, 17, 9, 11};
    SegmentTree st(arr);

    // Print the segment tree after building (only used nodes)
    st.print();

    // Query 1: Sum from index 1 to 3
    int startIndex = 0, endIndex = 3;
    cout << "\nSum from index " << startIndex << " to " << endIndex << " = " << st.rangeSum(startIndex, endIndex) << "\n";

    // Update operations:
    st.updateValue(0, 50);
    st.updateValue(1, 100);

    // Query 2: Sum from index 1 to 3 (After update operation)
    cout << "Sum from index " << startIndex << " to " << endIndex << " (After Update) = " << st.rangeSum(startIndex, endIndex) << "\n\n";

    // Print the segment tree after updates (only used nodes)
    st.print();

    return 0;
}
