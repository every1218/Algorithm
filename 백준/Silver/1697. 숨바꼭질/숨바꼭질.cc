#include <bits/stdc++.h>
using namespace std;

int dist[100002];
queue<int>q;

int main() {
    int n, k;
    cin>>n>>k;
    
    fill(dist, dist+100001, -1);
    dist[n] = 0;
    q.push(n);
    
    while(dist[k] == -1){
        int cur = q.front();
        q.pop();
        
        for(int i : {cur-1, cur+1, cur*2}){
            if(i<0 || i>100000) continue;
            if(dist[i] != -1) continue;
            dist[i] = dist[cur] +1; q.push(i);
        }
    }
    
    cout<<dist[k];
}