#include <bits/stdc++.h>
#define st first
#define ed second
using namespace std;


bool fun(pair<int, int>a, pair<int, int>b){
    if(a.st==b.st){
        return a.ed<b.ed;
    }
    return a.st<b.st;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    
    pair<int, int>p[200000];
    
    for(int i=0; i<n; i++){
        cin>>p[i].st>>p[i].ed;
    }
    
    sort(p, p+n, fun);
    
    int cnt=0;
    
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순 
    
    pq.push(p[0].ed);
    cnt++;
    
    for(int i=1; i<n; i++){
        bool find=false;
        
        if(pq.top()<= p[i].st){ //남는 강의실이 있으면
            pq.pop();
            find=true;
            pq.push(p[i].ed);
            continue;
        }
        
        if(!find){ //남는 강의실이 없으면
            cnt++;
            pq.push(p[i].ed);
        }
    }
    
    cout<<cnt<<'\n';
    
    // for(int i=0; i<n; i++){
    //     cout<<p[i].st<<' '<<p[i].ed<<'\n';
    // }

}