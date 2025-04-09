#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m;
    
    map<string,int> mp;
    
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        
        if(mp.find(str) != mp.end()){
            mp[str]++;
        }else{
            mp.insert({str, 1});
        }
        //map사용 
        //행을 문자열 형태로 키에 저장
        //그 문자열이 입력된 수를 값에 저장
    }
    cin>>k;
    
    int ans=0;     
    for (auto& p : mp) {
        int num=0; //키(string)의 0의 개수
        for(int i=0; i<m; i++){
            if(p.first[i]=='0')
                num++;
        }
        if(k%2==0){ //스위치 횟수가 짝수면
            if(num%2==0 && num<=k){  //키(string)의 0개수가 짝수인 것만
                ans=max(ans,p.second);  //값(int) 최대치 저장
            }
        }else{
            if(num%2==1 && num<=k){
                ans=max(ans,p.second);  
            }
        }
        
        // cout << p.first << ": " << p.second <<'\n';
    }
    
    cout<<ans;
}

