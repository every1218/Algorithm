#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    
    int cnt=0;
    int arr[101]; //전기용품 플러그 사용 순서
    vector<int>plug;
    vector<vector<int>>v(101); //인덱스 배열
    
    //전기용품별 인덱스 배열을 만들기
    for(int i=1; i<=k; i++){
        cin>>arr[i];
        v[arr[i]].push_back(i);
    }
    
    for(int i=1; i<=k; i++){
        //도구가 이미 플러그에 꽂혀있으면 -> 넘어가기
        bool temp=false;
        for(int j=0; j<plug.size(); j++){
            if(arr[i]==plug[j]){
                v[arr[i]].erase(v[arr[i]].begin()); //꽂은 장비의 인덱스 제거
                temp=true;
            }
        }
         if(temp==true) continue;
        
        
        //플러그가 남으면 -> 새로 꽂기
        if(plug.size()<n){
            v[arr[i]].erase(v[arr[i]].begin()); //꽂은 장비의 인덱스 제거
            plug.push_back(arr[i]);
        }else { //플러그가 꽉차면
            //플러그에 꽂힌 애들 중에 첫번째 인덱스가 제일 큰놈 제거
            // =순서상 나중에 오는 애를 먼저 교체
            int mx_plug=0;
            int mx=0;
            for(int j=0; j<plug.size(); j++){
                if(v[plug[j]].empty()){
                    mx_plug = j;
                    break;
                }
                if(mx<v[plug[j]].front()){
                    mx = max(mx, v[plug[j]].front());
                    mx_plug =j;
                }
            }
            plug.erase(plug.begin()+mx_plug); //플러그에 꽂힌 애 중 제일 나중에 오는 놈 제거
            plug.push_back(arr[i]); //새로 꽂기
            v[arr[i]].erase(v[arr[i]].begin()); //꽂은 장비의 인덱스 제거
            cnt++;
        }
    }
    
    // for(int j=0; j<plug.size(); j++){
    //     cout<<plug[j]<<' ';
    // }
    
    // for(int i=1; i<=k; i++){
    //     cout<<"i:"<<i << " =>";
    //     for(int j=0; j<v[i].size(); j++){
    //         cout<<v[i][j] <<' ';
    //     }cout<<'\n';
    // }

    cout<<cnt;
    
}