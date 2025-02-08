#include <iostream>
using namespace std;

int main() {
    int e,s,m;
    cin>>e>>s>>m;
    
    int cnt=0;
    
    while(e>1 || s>1 || m>1){
        e==1 ? e=15 : e--;
        s==1 ? s=28 : s--;
        m==1 ? m=19 : m--;
        cnt++;
    }
    cnt++;
    
    cout<<cnt<<endl;
}
