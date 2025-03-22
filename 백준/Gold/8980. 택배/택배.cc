#include <bits/stdc++.h>
using namespace std;

struct Truck{
    int st;
    int ed;
    int num;
};
bool compare(Truck a, Truck b){
    if(a.st==b.st && a.ed==b.ed)
        return a.num<b.num;
    if(a.st==b.st)
        return a.ed<b.ed;
    return a.st<b.st;
}


int main() {
    //일단 되는대로 다 담았다가 (ex 1-4 20 이런 거도)
    //더 가까운 거 있으면 버리고 그거 담기 (ex 2-3 20)
    
    int n, c, m;
    cin>>n>>c>>m;
    
    Truck t[2001];
    vector<Truck>v;
    int size=0;
    
    for(int i=0; i<m; i++){
        cin>>t[i].st>>t[i].ed>>t[i].num;
    }
    
    sort(t, t+m, compare);
    
    int ans=0;
    for(int i=0; i<m; i++){
        // cout<<"i : "<<i<<'\n';
        vector<int>temp;
        for(int j=0; j<v.size(); j++){
            if(t[i].st >= v[j].ed){
                ans+=v[j].num;
                size -= v[j].num;
                temp.push_back(j);
            }
        }
        for(int j=0; j<temp.size(); j++){
            v.erase(v.begin()+temp[j]);
        }
        
        
        if(size<c){
            if(size+t[i].num>c){
                v.push_back({t[i].st, t[i].ed, c-size});
                size = c;
            }else{
                size += t[i].num; 
                v.push_back({t[i].st, t[i].ed, t[i].num});
            }
        } 
        else if(size==c){
            vector<int>del;
            for(int j=0; j<v.size(); j++){
                if(t[i].ed < v[j].ed){
                    if(t[i].num>v[j].num){
                        v.push_back({t[i].st, t[i].ed, v[j].num});
                        t[i].num-=v[j].num;
                        del.push_back(j);
                    }
                    else{ //t[i].num<=v[j].num
                        v.push_back({t[i].st, t[i].ed, t[i].num});
                        v[j].num-=t[i].num;
                        t[i].num=0;
                    }
                }
            }
            for(int j=0; j<del.size(); j++){
                v.erase(v.begin()+del[j]);
            }
        }
        
        // for(int i=0; i<v.size(); i++){
        //     cout<<"    "<<v[i].st<<' '<<v[i].ed<<' '<<v[i].num<<'\n';
        // }
        // cout<<"    size :"<<size<<'\n';
        // cout<<"    ans :"<<ans<<'\n';
    }
    
    for(int j=0; j<v.size(); j++){
        ans+=v[j].num;
    }
    
    cout<<ans<<'\n';
    
    
}