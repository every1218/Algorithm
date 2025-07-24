#include <iostream>
using namespace std;

int fun(int n){
    if(n==0){
        return 1;
    }else{
        return n*fun(n-1);
    }
}


int main() {
    int n,k;
    cin>>n>>k;
    
    cout<<fun(n)/(fun(k)*fun(n-k));
}



//(n)
//(k)
 
//n!
//--------
//k!(n-k)!

//이항 계수)https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=junhyuk7272&logNo=222053814549
