#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int num;
    int x,y;
    int x_min=10000, x_max=-10000, y_min=10000, y_max=-10000;
    cin>>num;    
    while(num--){
        cin>>x>>y;
        if(x<x_min)
            x_min = x;
        if(y<y_min)
            y_min = y;
        if(x>x_max)
            x_max = x;
        if(y>y_max)
            y_max = y;
    }
    
    cout<< (x_max-x_min) * (y_max-y_min)<<endl;
}

