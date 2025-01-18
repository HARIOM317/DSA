#include <iostream>

using namespace std;

// Square of Numbers (Index of Row Starting from 1)
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<i<<" ";
        } cout<<endl;
        
    }
    

    return 0;
}