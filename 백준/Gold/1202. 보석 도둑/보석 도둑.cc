#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    else return a.second > b.second;
}

int main() {
    int n, k; // 보석 개수, 가방 개수
    cin>>n>>k;
    vector<int> bag; //가방
    vector<pair<int, int>> jew(n); //보석 벡터 (페어)
    priority_queue<int> pq; //현재 가방 용량 >=보석 무게를 만족하는 우선순위큐
    
    
    for(int i=0; i<n; i++){
        cin>>jew[i].first>>jew[i].second;
    }
    
    for(int i=0; i<k; i++){
        int temp;
        cin>>temp;
        bag.push_back(temp);
    }
    
    sort(bag.begin(), bag.end()); // 가방 : 오름차순 정렬
    sort(jew.begin(), jew.end()); //보석 :무게와 가격 중 가격기준으로 오름차순 정렬
    
    long long ans=0;
    int idx=0; //보석 인덱스
    
    for(int i=0; i<k; i++){ //가방 
        while(idx<n && bag[i] >= jew[idx].first){//현재 가방 용량 >= 보석 무게
            pq.push(jew[idx].second); //우선순위 큐에 가격 넣기
            idx++;
        }
        if(!pq.empty()){
            ans += pq.top(); //우선순위 top = 가격이 제일 비싼 보석
            pq.pop(); //top 삭제
        }
    }
    
    cout<<ans;
    
}
