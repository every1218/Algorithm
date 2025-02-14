#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool temp(pair<int, int> a, pair<int, int> b){
    if(a.Y == b.Y){ //만약 같다면
        return a.X<b.X;
    }else  //다르면
        return a.Y<b.Y;
}

int main() {
    int n;
    cin>>n;
    
    pair<int, int>p[100001];
    for(int i=0; i<n; i++){
        cin>>p[i].X>>p[i].Y;
    }
    
    sort(p, p+n, temp);
    
    int ans=0, t=0;
    for(int i=0; i<n; i++){
        if(t<=p[i].X){
            ans++;
            t=p[i].Y;
        }
    }
    cout<<ans;
    
    // for(int i=0; i<n; i++){
    //     cout<<p[i].X<<' '<<p[i].Y<<'\n';
    // }
    
}