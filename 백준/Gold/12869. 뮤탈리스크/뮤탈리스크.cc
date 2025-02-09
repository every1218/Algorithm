#include <bits/stdc++.h>
using namespace std;

int dp[61][61][61]={0};
int scv[3];
int dx[6] = {1,1,3,3,9,9};
int dy[6] = {3,9,1,9,1,3};
int dz[6] = {9,3,9,1,3,1};

struct state{
    int x;
    int y;
    int z;
};

int main() {
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>scv[i];
    }
    if(n==1) {scv[1]=0; scv[2]=0;}
    if(n==2) scv[2]=0;
    
    fill(&dp[0][0][0], &dp[60][60][61], INT_MAX);
    
    queue<state>q;
    q.push({scv[0], scv[1], scv[2]});
    dp[scv[0]][scv[1]][scv[2]] = 0;
    
    while(!q.empty()){
        int nx, ny, nz;
        state cur = q.front(); q.pop();
        
        
        for(int l=0; l<6; l++){
            nx = cur.x - dx[l];
            ny = cur.y - dy[l];
            nz = cur.z - dz[l];
            
            if(nx<0) nx=0;
            if(ny<0) ny=0;
            if(nz<0) nz=0;
            
            if(dp[nx][ny][nz] != INT_MAX) continue;
            
            dp[nx][ny][nz] = min(dp[nx][ny][nz], dp[cur.x][cur.y][cur.z]+1);
            
            if(nx==0 && ny==0 && nz==0){
                cout<<dp[0][0][0];
                return 0;
            }
            
            q.push({nx,ny,nz});
        }
    }
}