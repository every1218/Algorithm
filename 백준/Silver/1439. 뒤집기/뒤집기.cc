#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;
    
    int zero=0;
    int one=0;
    
    for(int i=0; i<str.length(); i++){
        if(str[i]=='0' && (str[i+1]=='1' || str[i+1]==NULL))
            zero++;
        else if(str[i]=='1' && (str[i+1]=='0' || str[i+1]==NULL))
            one++;
        else continue;
    }
    
    cout<<min(zero, one);
}