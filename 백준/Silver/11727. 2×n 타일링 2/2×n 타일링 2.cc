#include <iostream>
using namespace std;

int main() {
    int d[1001];
    
    d[1] = 1;
    d[2] = 3;
    
   int num;
   cin>>num;
   for(int i=3; i<=num; i++){
       d[i] = d[i-1] + d[i-2]*2;
       d[i] %= 10007;
   }
   
   cout<<d[num];
   
}