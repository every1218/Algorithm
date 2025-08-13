#include <iostream>
using namespace std;

int main() {    
    int n,m;
    cin>>n>>m;
    
    int num;
    int a[n][m];
    int b[n][m];
    
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>num;
            a[i][j] =num;
        }
    }
    
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>num;
            cout <<a[i][j]+num<<' ';
        }
        cout<<endl;
    }
    
    
    
}