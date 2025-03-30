#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    int ans[500001] ={0};
    stack<pair<int,int>>s1, s2;
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        s1.push({temp, i});
    }
    
    while(!s1.empty()){
        while(!s2.empty() && s1.top().first>=s2.top().first){
           ans[s2.top().second] = s1.top().second;
           s2.pop();
        }
        s2.push(s1.top());
        s1.pop();
    }
    
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<' ';
    }
}