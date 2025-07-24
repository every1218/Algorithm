#include <bits/stdc++.h>
using namespace std;

int a[129][129];
int cnt[2];

bool check(int n, int x, int y){
    bool temp0 = true;
    bool temp1 = true;
    for(int i=x; i<n+x; i++){
        for(int j=y; j<n+y; j++){
            if(a[i][j] == 1)
                temp0 = false;
            else
                temp1 = false;
        }
    }
    if(temp0){
        cnt[0] +=1;
        return false;
    }else if(temp1){
        cnt[1] +=1;
        return false;
    }else
        return true;
}


void fun(int n, int x, int y){
    if(n==1){
        cnt[a[x][y]] += 1;
        return;
    }
    
   if(check(n,x,y)){
       fun(n/2, x, y);
       fun(n/2, x, y + n/2);
       fun(n/2, x + n/2, y);
       fun(n/2, x + n/2, y + n/2);
   }
}


int main() {
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    
    fun(n,0,0);
    
    cout<<cnt[0]<<'\n';
    cout<<cnt[1]<<'\n';
}