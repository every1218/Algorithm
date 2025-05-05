#include <iostream>
#include <stack>
using namespace std;

int main() {
    while(1){
        stack<char>s;
        
        string str = "";
        getline(cin, str);
        
        if(str =="."){
            break;
        }
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == '.')
                break;
            
            else if(str[i] == '('){
                s.push('(');
            }else if(str[i] == ')'){ 
                if(s.empty()){
                    s.push('1');
                }else if(s.top() == '('){
                    s.pop();
                }else{
                    s.push('1');
                }
            }
            
            else if(str[i] == '['){
                s.push('[');
            }else if(str[i] == ']'){
                if(s.empty()){
                    s.push('1');
                } else if(s.top() == '['){
                    s.pop();
                } else{
                    s.push('1');
                }
            }
        }
        
        if(s.empty()){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    
}