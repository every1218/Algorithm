#include <bits/stdc++.h>
using namespace std;

struct day{
    int sm, sd, em,ed;
};

bool temp (day a, day b){
    if(a.sm != b.sm) return a.sm<b.sm;
    if(a.sd != b.sd) return a.sd<b.sd;
    if(a.em != b.em) return a.em<b.em;
    return a.ed<b.ed;
}

int main() {
    int n;
    cin>>n;
    
    day d[100001];
    
    for(int i=0; i<n; i++){
        cin>>d[i].sm>>d[i].sd>>d[i].em>>d[i].ed;
    }
    
    //잠시만 sort함수로 정렬을 해야하나?
    //일단 이전코드처럼 해보고 그다음 트라이
    sort(d, d+n, temp);
    
    
    //이거 없어도 되지않나?
    if(d[0].sm>3 || (d[0].sm==3 && d[0].sd>1)){
        cout<<0<<'\n';
        return 0;
    }
    
    day p = {0,0,3,1};
    
    int index=0, flower=0;
    
    while(p.em<12){
        int mx_index=-1;
        int mx_em = p.em, mx_ed = p.ed; 
        
        for(int i=index; i<n; i++){
            // 1. d[i].s보단 크거나 같고
            // 2. d[i].e보단 작아야함
            if(p.em>d[i].sm || (p.em==d[i].sm && p.ed>=d[i].sd)){
                if(mx_em<d[i].em || (mx_em==d[i].em && mx_ed<d[i].ed)){
                    mx_em = d[i].em;
                    mx_ed = d[i].ed;
                    mx_index=i; 
                }
            }
        }
        // cout<<"mx_em : "<<mx_em<<' '<<mx_ed<<'\n';
        // cout<<"mx_index :"<<mx_index<<'\n'<<'\n';
        
       if(mx_index==-1){
            cout<<0<<'\n';
            return 0;
        }
        
        p = d[mx_index];
        index = mx_index+1;
        flower++;
    }
    
    cout<<flower;
}