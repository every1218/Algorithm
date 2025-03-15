#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    pair<int, int>p[1000001];
    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        
        p[i] ={x, y};
    }
    
    sort(p, p+n);
    
    
    // for(int i=0; i<n; i++){
    //     cout<<p[i].X<<' '<<p[i].Y<<'\n';
    // }
    
    long long ans=0;
    int mx=INT_MIN;
    
    for(int i=0; i<n; i++){
        if(p[i].X<mx) p[i].X=mx;
        if(p[i].X<p[i].Y){
            ans += p[i].Y-p[i].X;
            mx = p[i].Y;
        }
        // cout<<"i : "<<i<<", ans : "<<ans<<'\n';
        
    }

    cout<<ans;
    
}

