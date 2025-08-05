#include <iostream>
using namespace std;

int main() {
    int arr[100]={0}; 
    int m,n;
    cin >> n>>m;

    for (int i=1;i<n+1;i++){
        arr[i] = i;
    }
    
    while(m--){
        int a,b,temp;
        cin >> a>>b;
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    
    for (int i=1;i<n+1;i++){
        cout << arr[i]<<' ';
    }
}