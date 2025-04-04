#include <bits/stdc++.h>
using namespace std;

struct Truck{
    int st, ed, wg;
};

bool compare(const Truck& a, const Truck& b) {
    if(a.ed==b.ed) return a.st<b.st;
    else return a.ed < b.ed; 
}

int main() {
    int n, c, m; //마을수, 트럭용량, 박스 개수
    cin>>n>>c>>m;
    
    Truck t[10005];
    int v[2005]={0}; //마을 정보
    
    for(int i=1; i<=m; i++){
        int a1, a2, a3;
        cin>>a1>>a2>>a3;
        t[i] = {a1,a2,a3};
    }
    
    sort(t+1, t+m+1, compare);
    
    
    // for(int i=1; i<=m; i++){  
    //     cout<<t[i].st<<' '<<t[i].ed<<' '<<t[i].wg<<'\n';
    // }
    
    int ans=0;
    for(int i=1; i<=m; i++){  
        int mn=INT_MAX;
        for(int j=t[i].st; j<t[i].ed; j++){
            if(v[j]+t[i].wg > c){ 
                mn = min(mn,c-v[j]);
            }else{
                mn = min(mn,t[i].wg);
            }
        }
        
        for(int j=t[i].st; j<t[i].ed; j++){
            v[j] += mn;
        }
        ans += mn;
        
        // cout<<"i="<<i<<" : "<<ans<<'\n';
        // for(int i=1; i<=n; i++){  
        //     cout<<"     "<<v[i]<<' ';
        // }cout<<'\n';
    }
    cout<<ans;

}
