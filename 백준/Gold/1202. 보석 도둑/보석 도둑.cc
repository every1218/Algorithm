#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    else return a.second > b.second;
}

int main() {
    int n, k; // 보석 개수, 가방 개수
    cin>>n>>k;
    multiset<int> bag; //가방 (멀티셋 - 자동정렬)
    vector<pair<int, int>> jew(n); //보석 벡터 (페어)
    
    
    for(int i=0; i<n; i++){ 
        cin>>jew[i].first>>jew[i].second;
    }
    
    //보석 벡터 : 가격기준으로 정렬
    sort(jew.begin(), jew.end(), compare);
    
    for(int i=0; i<k; i++){
        int temp;
        cin>>temp;
        bag.insert(temp);
    }
    
    long long ans=0;
    
    for(auto i=jew.begin(); i<jew.end(); i++){
        int weight = i->first;
        int price = i->second;
        
        auto it = bag.lower_bound(weight); //보석의 무게보다 높은 첫번째 가방의 인덱스로 이동
        if(it != bag.end()){              //=현재 보석을 담을 수 있는 가장 작은 가방 찾기
            ans+=price;  //결과 += 보석의 가격
            bag.erase(it); //담은 가방은 삭제
        }
    }
    
    cout<<ans;
    
}
