#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

multimap<int, string>m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin>>num;
    
    while(num--){
        int age;
        string name;
        cin>>age>>name;
        m.insert({age, name});
    }
    
    for(auto iter=m.begin(); iter!=m.end();iter++){
        cout<<iter->first<<' '<<iter->second<<'\n';
    }
    
}