#include <iostream>
#include <set>
using namespace std;


int main() {
    int n,m;
    int cnt=0;
    cin>>n>>m;
    
    set<string>s;    
    set<string>people;
    
    for(int i=0;i<n;i++){
        string str; 
        cin>>str;
        s.insert(str);
    }
    
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        
        if(s.find(str) != s.end()){
            people.insert(str);
            cnt++;
        }
    }
    
    cout<<cnt<<'\n';
    for(auto iter =people.begin();iter!=people.end();iter++){
        cout<<*iter<<endl;
    }
}