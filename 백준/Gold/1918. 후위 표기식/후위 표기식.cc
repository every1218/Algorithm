#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<char>s;
    
    string str, ans;
    cin>>str;
    
    for(int i=0; i<str.length(); i++){
        if(isupper(str[i]))
            ans += str[i];
        else{
            if(s.empty() || (str[i]=='(')){
                s.push(str[i]);
            }else if(str[i]==')'){
                while(!s.empty() && s.top() != '('){
                    ans += s.top();
                    s.pop();
                }
                if(!s.empty()) s.pop(); // ( 제거
            }else {
                while (!s.empty() && s.top() != '(' &&
                        ((s.top() == '*' || s.top() == '/') || (str[i] == '+' || str[i] == '-'))) {
                    ans += s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
    }
    
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    
    cout<<ans;
}