#include <bits/stdc++.h>
using namespace std;

struct Truck{
    int st; // 출발 마을
    int ed; // 도착 마을
    int num; // 박스 개수
};

// 정렬 기준: 도착 마을 오름차순
bool compare(Truck a, Truck b){
    if(a.ed == b.ed)
        return a.st < b.st;
    return a.ed < b.ed;
}

int main() {
    int n, c, m;
    cin >> n >> c >> m;
    
    vector<Truck> t(m); // 트럭 정보 저장
    vector<int> v(n+1, 0); // 각 마을에서 트럭이 실은 박스 수

    for(int i = 0; i < m; i++){
        cin >> t[i].st >> t[i].ed >> t[i].num;
    }
    
    sort(t.begin(), t.end(), compare);
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        // cout<<"i : "<<i<<'\n';
        bool loadable = true;
       
        for(int j=t[i].st; j < t[i].ed; j++){
            t[i].num = min(t[i].num, c - v[j]);
            // cout<<"     t[i].num:"<<t[i].num<<'\n';
            if (t[i].num == 0) {
                loadable = false;
                break;
            }
        }
        if (loadable) {
            ans += t[i].num;
            for (int j = t[i].st; j < t[i].ed; j++) 
                v[j] += t[i].num;
        }
        
        // for(int j=1; j <= n; j++){
        //     cout<<"     "<<v[j]<<' ';
        // }cout<<'\n';
        // cout<<"     ans:"<<ans<<'\n';
    }
    
    cout << ans << '\n';
}