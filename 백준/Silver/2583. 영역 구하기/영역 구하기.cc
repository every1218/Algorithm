#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] ={1,0,-1,0};
int dy[4] ={0,1,0,-1};

int main() {
    int m, n, k;
    cin>>m>>n>>k;
    
    bool board[102][102]={0};
    int vis[102][102]={0};
    
    while(k--){
        int l_x, l_y, u_x, u_y; //lower xy, upper xy
        cin>>l_x>>l_y>>u_x>>u_y; //0,2  4,4
        
        for(int i = l_y; i<u_y; i++){ 
            for(int j = l_x; j<u_x; j++){ 
                board[i][j]=1;
            }
        }
    }
   
    int area=0;
    vector<int>v;
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(!board[i][j] && !vis[i][j]){
                queue<pair<int, int>>q;
                int temp=1;
                q.push({i, j});
                vis[i][j]=1;
                
                while(!q.empty()){
                    pair<int, int>cur = q.front(); q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        
                        if(nx<0 || nx>=m || ny<0 || ny>=n)continue;
                        if(board[nx][ny] || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        temp++;
                        q.push({nx,ny});
                    }
                }
                v.push_back(temp);
                area++; 
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout<<area<<'\n';
    for(auto iter=v.begin(); iter!=v.end(); iter++){
        cout<<*iter<<' ';
    } //cout<<'\n'; cout<<'\n';
    
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<board[i][j]<<' ';
    //     }cout<<'\n';
    // }
    // cout<<'\n'; 
}