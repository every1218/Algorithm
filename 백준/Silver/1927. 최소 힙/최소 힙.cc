#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    
    priority_queue<int, vector<int>, greater<int>>pq;
    
    for (int i=0; i<n; i++){
        int temp;
        cin>>temp;
        if(temp==0){
            if(pq.empty()) cout<<0<<'\n';
            else {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }else{
            pq.push(temp);
        }
    }

}