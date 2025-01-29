#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] ={1,0,-1,0};
int dy[4] ={0,1,0,-1};
bool board[27][27];
int vis[27][27];

int main() {
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        string str;
        cin>>str;
        for(int j=1; j<=n; j++){
            board[i][j] = str[j-1]-'0';
        }
    }
    
    vector<int>v;
    int area=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] && !vis[i][j]){
                queue<pair<int, int>>q;
                q.push({i, j});
                vis[i][j]=1;
                int temp =1;
                
                while(!q.empty()){
                    pair<int, int>cur = q.front(); q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        
                        if(nx<0 || nx>n || ny<0 || ny>n)continue;
                        if(!board[nx][ny] || vis[nx][ny]) continue;
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
    
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<vis[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
    cout<<area<<'\n';
    for(int i : v){
        cout<<i<<'\n';
    }
}