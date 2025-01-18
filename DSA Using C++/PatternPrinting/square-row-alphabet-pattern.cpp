#include <iostream>

using namespace std;

// Square of Alphabet
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    char ch = 'A';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<ch<<" ";
        } cout<<endl;
        ch++;
    }

    return 0;
}