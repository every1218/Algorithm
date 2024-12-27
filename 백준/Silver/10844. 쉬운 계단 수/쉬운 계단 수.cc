#include <iostream>
#define mod 1000000000

using namespace std;

int d[101][10] = {0};

int main() {
    int num;
    cin>>num;
    
    for(int i=1; i<10; i++){
        d[1][i] = 1;
    }
    
    for(int i=2; i<=num; i++){
        for(int j=0; j<10; j++){
            if(j==0) { 
                d[i][0] = d[i-1][1];
            }else if(j==9){
                d[i][9] = d[i-1][8];
            }else{
                d[i][j] = d[i-1][j-1] + d[i-1][j+1];    
            }
            d[i][j] %= mod;
        }
    }
        
    int cnt =0;
    for(int i=0; i<10; i++){
        cnt = (cnt + d[num][i] )% mod;
        
    }
    cout<<cnt;
}