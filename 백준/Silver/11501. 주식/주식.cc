#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second  

//1. 제일 큰수보다 낮으면 사기 (벡터에 저장)
//2. 제일큰수가 되면 다 팔기. 다음으로 제일큰수한테 인계
//    ㄴ 이미 지나지 않은 주식 중에 인계 (pair로 저장해둔 index로 판단)

bool fun(pair<int, int>a, pair<int, int>b){
    return a.X<b.X;
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        pair<int, int>p[1000001];
        pair<int, int>mx_arr[1000001];
        pair<int, int>mx;
        int mx_index = n-1;
        vector<int>v;
        long long ans=0;
        
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            p[i] = {temp, i};
            mx_arr[i]= {temp, i};
        }
        sort(mx_arr, mx_arr+n, fun);
        
        mx = mx_arr[mx_index];
        
        for(int i=0; i<n; i++){
            if(p[i].X<mx.X){
                v.push_back(p[i].X); //제일큰수보다 낮으면 사두기
            }
            if(p[i].X==mx.X){
                for(auto j:v){
                    ans += (mx.X-j); //사둔 주식들 제일 큰수랑 차이만큼 더하기
                }
                v.clear();
                
                //이미 지나지 않은 주식 중 다음으로 제일 큰수한테 인계
                while(mx.Y<=i){ 
                    if(mx_index==0) break;
                    mx_index--;
                    mx=mx_arr[mx_index]; 
                }
            }
        }
        
        cout<<ans<<'\n';
        // cout<<"mx : "<<mx.X<<'\n';
        
    }
}

