#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> arr, int n, int m, int maxAllowedPages)
{
    int numberOfStudent = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedPages)
            return false;

        if (pages + arr[i] <= maxAllowedPages)
        {
            pages += arr[i];
        }
        else
        {
            numberOfStudent++;
            pages = arr[i];
        }
    }

    return numberOfStudent > m ? false : true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    if (m > n)
        return -1;

    int sum = 0;
    // getting sum of all elements which is max possible value to allocate pages
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int start = 0, end = sum; // range of possible answer
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n = 4, m = 2;
    vector<int> arr = {2, 1, 3, 4}; // ans = 2+1+3 = 6

    cout << "Minimum pages allocates = " << allocateBooks(arr, n, m) << endl;

    return 0;
}