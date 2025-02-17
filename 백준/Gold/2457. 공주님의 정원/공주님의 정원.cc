#include <bits/stdc++.h>
using namespace std;

// 그럼 간단하게 말해서 지는 날이 늦으면 좋은 거잖아

// 다음 꽃의 시작(6.10)이 현재 꽃의 끝(6.30)보다 같거나 작고,
// 다음 꽃의 끝이(12.10) 현재 꽃의 끝(6.30)보다 크면 되는 거잖아.
// 이 조건을 만족하는 가장 마지막 다음 꽃을 고르면 되네?

struct day{
    int sm; //start month
    int sd; 
    int em; //end month
    int ed;
};

bool temp(day a, day b){
    if(a.sm != b.sm) return a.sm<b.sm;
    if (a.sd != b.sd) return a.sd<b.sd;
    if (a.em != b.em) return a.em<b.em; 
    return a.ed<b.ed;
}


int main() {
    int n; 
    cin>>n;
    
    day d[100002];
    
    for(int i=0; i<n; i++){
        cin>>d[i].sm>>d[i].sd>>d[i].em>>d[i].ed;
    }
    
    sort(d, d+n, temp);
    
    if(d[0].sm > 3 || d[0].sm==3 && d[0].sd>1){
        cout<<0<<'\n';
        return 0;
    }
    
    day p = {0,0,3,1}; //present
    int flower=0;
    int index=0;
    
    while(p.em<12){
        int last_index = -1;
        int max_em = p.em, max_ed = p.ed;
        
        for (int i = index; i < n; i++) {
            if (d[i].sm > p.em || (d[i].sm == p.em && d[i].sd > p.ed)) break;
            if (d[i].em > max_em || (d[i].em == max_em && d[i].ed > max_ed)) {
                last_index = i;
                max_em = d[i].em;
                max_ed = d[i].ed;
            }
        }
        
        if (last_index == -1) {
            cout<<0<<'\n';
            return 0;
        }
        
        p.em = d[last_index].em; 
        p.ed = d[last_index].ed;
        flower++;
        index=last_index+1;
    }
    cout<<flower<<'\n';
}