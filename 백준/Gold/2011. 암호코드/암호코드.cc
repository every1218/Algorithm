#include <bits/stdc++.h>
using namespace std;

int dp[5001] ={1,1};

int main() {
    string pw="0", temp;
    cin>>temp;
    
    pw.append(temp);
    
    if(pw[1]=='0'){
        cout<<0;
        return 0;
    }
    
    for(int i=2; i<pw.length(); i++){
    	if(pw[i]=='0'){
            if(pw[i-1]=='1' || pw[i-1]=='2'){
                // dp[i]=min(dp[i-1], dp[i-2]) % 1000000;
                dp[i]= dp[i-2] % 1000000;
            }else{
                cout<<0;
                return 0;
            }
        }else if((pw[i-1]-'0')*10 + (pw[i]-'0') > 26){
    		dp[i] = dp[i-1] % 1000000;
    	}else if(pw[i-1]=='0'){
    		dp[i] = dp[i-1] % 1000000;
    	}else{
    		dp[i] = (dp[i-1] + dp[i-2]) % 1000000;
        }
    }
    
    cout<<dp[pw.length()-1]<<'\n';
    
    // for(int i=1; i<pw.length(); i++){
    //     cout<<"dp["<<i<<"] :"<<dp[i]<<'\n';
    // }
}