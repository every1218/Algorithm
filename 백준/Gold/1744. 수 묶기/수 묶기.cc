#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main() {
    int n;
    cin>>n;
    
    pair<int, bool>p[51];
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        p[i] ={temp, false};
    }
    
    sort(p, p+n);
    
    if(n==1){
        cout<<p[0].X<<'\n';
        return 0;
    }
    
    int cnt=0;
    
    //양수에서 큰거끼리 묶다가 0보다 작거나 같아지면 멈춤
    for(int i=n-1; i>0; i-=2){ 
        if(p[i].X==1 || p[i-1].X==1) { //1 있을 때 더하기 예외처리
            cnt+=p[i].X+p[i-1].X; 
            p[i].Y = true; p[i-1].Y = true; 
            break; 
        }if(p[i].X<=0 || p[i-1].X<=0) break; //0보다 작거나 같아지면 멈춤
        else {
            cnt+=p[i].X*p[i-1].X;
            p[i].Y = true; 
            p[i-1].Y = true; 
        }
    } 
    
    //음수에서 작은 순대로 묶다가 0 커지면 멈춤
    for(int i=0; i<n-1; i+=2){
        if(p[i].X>0 || p[i+1].X>0 )break; //0보다 크거나 같아지면 멈춤
        else {
            cnt+=p[i].X*p[i+1].X;
            p[i].Y = true; 
            p[i+1].Y = true; 
        }
    }
    
    for(int i=0; i<n; i++){
        if(p[i].Y == false){
            cnt+=p[i].X;
        }
    }

    cout<<cnt;
}