#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;
    
    int ans=0;
    bool sign=0; //+
    
    string temp;
    for(int i=0; i<=str.length(); i++){
        if(str[i]-'0' >= 0 && str[i]-'0'<=9){ //숫자일 때
            temp += str[i];
        }else{ //기호 or 공백문자일 때
            if(sign==0) ans +=stoi(temp);
            else ans -= stoi(temp);
            temp="";
            
            if(str[i] == '-') sign=1; //한번 -가 나오면 그 뒤 모든 숫자는 -로 취급
        }
    }
    
    cout<<ans;
}