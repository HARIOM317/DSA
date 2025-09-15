#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int mx = -19999999;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nMax element till i are as follow: \n";
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
        cout << "Iteration " << i + 1 << " ---> " << mx << endl;
    }

    return 0;
}