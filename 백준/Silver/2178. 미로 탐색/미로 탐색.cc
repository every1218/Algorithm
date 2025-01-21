#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[101][101];
int vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int,int>>q;

int main() {
    int n,m;
    cin>>n>>m;
    
    string str;
    for(int i=0; i<n; i++){
        cin>>str;
        for(int j=0; j<m; j++){
            board[i][j] = str[j] - '0';
        }
    }
    
    vis[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty()){
        pair<int, int>cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
            if(board[nx][ny] == 0 || vis[nx][ny] !=0 ) continue;
            
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    cout<<vis[n-1][m-1];
    
}