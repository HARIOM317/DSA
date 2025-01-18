#include <iostream>

using namespace std;

/*
    1 2 3 4 4 3 2 1
    1 2 3 * * 3 2 1
    1 2 * * * * 2 1
    1 * * * * * * 1
*/
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    for(int i = 0; i < n; i++){
        int num = 1;
        for(int j = 1; j <= 2*n; j++){
            if(j <= n-i){
                cout<<num<<" ";
                num++;
            } else if(j > n+i){
                cout<<num-1<<" ";
                num--;
            } else {
                cout<<"* ";
            }
        } cout<<endl;
    }

    return 0;
}