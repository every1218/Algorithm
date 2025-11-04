#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    
    int temp = 1000-n;
    int cnt=0;
    
    while(temp>0){
        if(temp>=500){
            cnt++;
            temp-=500;
        }else if(temp>=100){
            cnt++;
            temp-=100;
        }else if(temp>=50){
            cnt++;
            temp-=50;
        }else if(temp>=10){
            cnt++;
            temp-=10;
        }else if(temp>=5){
            cnt++;
            temp-=5;
        }else if(temp>=1){
            cnt++;
            temp-=1;
        }
    }
    
    cout<<cnt;
    
    
}