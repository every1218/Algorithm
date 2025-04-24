#include <bits/stdc++.h>
using namespace std;

int k, n;
int line[10005];

bool fun(long long mid){
    long long cnt=0;
    for(int i=0; i<k; i++){
        cnt += line[i]/mid;
    }
    if(cnt>=n) return 1;
    else return 0;
}

int main() {
    cin>>k>>n;
    
    int mx=0;
    for(int i=0; i<k; i++){
        cin>>line[i];
        mx = max(mx, line[i]);
    }
    
    long long st=0, ed=mx;
    
    while(st<ed){
        long long mid=(st+ed+1)/2;
        if(fun(mid)){  //ex) 100보냄 24 >= 11  (크게크게 짤라야함)
            st = mid; 
        }else{ //ex) 0~800에서 400보냄 5 < 11 (더 쪼개야됨)
            ed = mid-1;  //(0~399)
        }
    }
    
    cout<<st;
    
}