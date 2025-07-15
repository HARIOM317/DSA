#include <iostream>

using namespace std;

// Time complexity: O(2^n)
void towerOfHanoi(int n, string src, string helper, string dest)
{
    // base case
    if (n == 0) {
        return;
    }

    // transfet top n-1 from src to helper using dest as 'helper'
    towerOfHanoi(n - 1, src, dest, helper);

    // transfer plate
    cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;

    // transfet n-1 from helper to dest using src as 'helper'
    towerOfHanoi(n - 1, helper, src, dest);
}

int main()
{
    int n = 3;
    towerOfHanoi(n, "A", "B", "C"); // A -> source, B -> helper, C -> destination

    return 0;
}