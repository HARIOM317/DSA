#include <iostream>
#include <vector>

using namespace std;

class FenwickTree
{
private:
    vector<int> tree; // 1-based indexing
    int n;

    // function to get last set bit (LSB)
    int LSB(int i)
    {
        return i & (-i);
    }

public:
    // Initialize tree with size elements (1-based)
    FenwickTree(int size)
    {
        n = size;
        tree.assign(n + 1, 0);
    }

    // to update a value
    void update(int index, int value)
    {
        while (index < n)
        {
            tree[index] += value;
            index += LSB(index);
        }
    }

    // to get prefix sum [1 to index]
    int query(int index)
    {
        int sum = 0;
        while (index > 0)
        {
            sum += tree[index];
            index -= LSB(index);
        }
        return sum;
    }

    // to get sum in rangle [l to r]
    int rangeQuery(int left, int right)
    {
        return query(right) - query(left - 1);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();

    // Creating Fenwick Tree with initial value 0
    FenwickTree ft(n);

    // Build Fenwick Tree
    for (int i = 0; i < n; i++)
    {
        ft.update(i + 1, arr[i]);
    }

    // Query : prefix sum from index 1 to 4
    cout << "Sum of first 4 elements : " << ft.query(4) << endl; // 1 + 2 + 3 + 4 = 10

    // Query : Subarray sum from index 2 to 7
    cout << "Sum from index 2 to 7 : " << ft.rangeQuery(2, 7) << endl; // 2 + 3 + 4 + 5 + 6 + 7 = 27

    // Update array
    ft.update(1, 10); // add 10 in tree[1]
    ft.update(2, 20); // add 20 in tree[2]
    ft.update(3, 30); // add 30 in tree[3]
    ft.update(4, 40); // add 40 in tree[4]

    // Query : Sum of first 4 elements
    cout << "Sum of first 4 elements (After Update) : " << ft.query(4) << endl; // 11 + 22 + 33 + 44 = 110

    return 0;
}