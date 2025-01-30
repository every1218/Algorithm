#include <bits/stdc++.h>
using namespace std;

int a[51], b[51];

bool cmp(int x, int y){
    return x>y;
}

int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    
    sort(a,a+n);
    sort(b,b+n,cmp);

    int s=0;
    for(int i=0; i<n; i++){
        s+=a[i]*b[i];
    }
    cout<<s<<'\n';
}