#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

char board[101][101];
bool per[101][101]; //일반인
bool rg[101][101]; //적녹색약
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        string str;
        cin>>str;
        for(int j=1; j<=n; j++){
            board[i][j] = str[j-1];
        }
    }
   
    int per_cnt =0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(per[i][j]) continue;
            
            queue<pair<int, int>>q;
            per_cnt++;
            per[i][j]=1;
            q.push({i, j});
            
            while(!q.empty()){
                pair<int, int> cur = q.front(); q.pop();
                
                for(int k=0; k<4; k++){
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];
                    
                    
                    if(nx<=0 || ny<=0 || nx>n || ny>n) continue; //그림을 벗어나면 
                    if(board[nx][ny] != board[i][j]) continue; ///색이 다르면
                    if(per[nx][ny]) continue; //이미 탐색했다면
                    
                    per[nx][ny] =1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    int rg_cnt =0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(rg[i][j]) continue;
            
            queue<pair<int, int>>q;
            rg_cnt++;
            rg[i][j]=1;
            q.push({i, j});
            
            while(!q.empty()){
                pair<int, int> cur = q.front(); q.pop();
                
                for(int k=0; k<4; k++){
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];
                    
                    if(nx<=0 || ny<=0 || nx>n || ny>n) continue; //그림을 벗어나면 
                    if(rg[nx][ny]) continue; //이미 탐색했다면
                    if(board[i][j] == 'R' && board[nx][ny] =='B') continue; 
                    if(board[i][j] == 'G' && board[nx][ny] =='B') continue; 
                    if(board[i][j] == 'B' && (board[nx][ny] =='R' || board[nx][ny] =='G')) continue; 
                    
                    rg[nx][ny] =1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<rg[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
    cout<<per_cnt<<' ';
    cout<<rg_cnt<<'\n';
}