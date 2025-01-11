#include <iostream>
using namespace std;

int main() {
    long long d[91] = {0, 1, 1};
    int num;
    cin>>num;
    
    for(int i=3; i<=num; i++){
        d[i] = d[i-1] + d[i-2];
    }
    cout<<d[num];
}

// 0시작  x, 1두번 연속 x 인 이진수 

// 2자리 이친추의 개수 : 1개
// 10

// 3자리 이친수의 개수 : 2개 
// 100
// 101

// 4자리 이친수 개수 : 3개
// 1000
// 1001
// 1010

// 5자리 이친수 개수 : 5개
// 10000
// 10010
// 10100
// 10001
// 10101


// 4자리 끝에가 0이 오는 경우) 3자리 이친수의 개수
// 4자리 끝에가 1이 오는 경우) 2자리 이친수의 개수

