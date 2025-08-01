#include <iostream>
using namespace std;

int main() {
    int arr[100]={0}; 
    int m,n,temp;
    cin >> n>>m;

    for (int i=1;i<n+1;i++){
        arr[i] = i;
    }

    while(m--){
        int a,b,temp;
        cin >> a>>b;
        
        for(int i=a; i<=(a+b)/2;i++){
            temp = arr[i];
            arr[i] = arr[a+b-i];
            arr[a+b-i] = temp;
        }
    }
 
    
    for (int i=1;i<n+1;i++){
        cout << arr[i]<<' ';
    }
    cout <<endl;
}