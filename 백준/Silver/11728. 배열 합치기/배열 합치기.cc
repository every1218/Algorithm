#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int b[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    
    int a_num=0, b_num=0;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<m; i++)
        cin>>b[i];
    
    queue<int>q;
    for(int i=0; i<n+m; i++){
        if(a_num>=n){
            q.push(b[b_num]);
            b_num++;
            continue;
        }else if(b_num>=m){
            q.push(a[a_num]);
            a_num++;
            continue;
        }
        
        if(a[a_num] < b[b_num]){
            q.push(a[a_num]);
            a_num++;
        }else{
            q.push(b[b_num]);
            b_num++;
        }
    }
    
    while(!q.empty()){
        cout<<q.front()<<' ';
        q.pop();
    }
    
}