#include <bits/stdc++.h>
using namespace std;

int dp[61][61][61]={0};
int scv[3];
int x[6] = {1,1,3,3,9,9};
int y[6] = {3,9,1,9,1,3};
int z[6] = {9,3,9,1,3,1};


int main() {
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>scv[i];
    }

    for(int i=0; i<61; i++){
        for(int j=0; j<61; j++){
            for(int k=0; k<61; k++){
                if(i==0 && j==0 && k==0)continue;
                int temp=INT_MAX;
                int t[3]={-1,-1,-1};
                for(int l=0; l<6; l++){
                    if(i-x[l]<0) t[0]=0; else t[0]=i-x[l];
                    if(j-y[l]<0) t[1]=0; else t[1]=j-y[l];
                    if(k-z[l]<0) t[2]=0; else t[2]=k-z[l];
                    
                    temp = min(temp, dp[t[0]][t[1]][t[2]]);
                }
                if(temp!=INT_MAX)
                    dp[i][j][k] = temp+1;
            }
        }
    }
    
    // for(int i=0; i<61; i++){
    //     for(int j=0; j<61; j++){
    //         for(int k=0; k<61; k++){
    //             cout<<"dp["<<i<<','<<j<<','<<k<<"] : "<<dp[i][j][k]<<'\n';;
    //         }
    //     }
    // }
    
    if(n==1){
        cout<<dp[scv[0]][0][0];
    }else if(n==2){
        cout<<dp[scv[0]][scv[1]][0];
    }else{
        cout<<dp[scv[0]][scv[1]][scv[2]];
    }
    
}