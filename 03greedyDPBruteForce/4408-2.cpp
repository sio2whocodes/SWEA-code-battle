//
//  4408-2.cpp
//  swea
//
//  Created by 임수정 on 2021/07/25.
//

#include<iostream>
#include<queue>
using namespace std;

struct comp{
    bool operator()(pair<int,int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }else{
            return a.first > b.first;
        }
    }
};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        priority_queue<int, vector<int>, greater<>> tq;

        int a,b;
        for(int i = 0 ; i < N ; i++){
            cin >> a >> b;
            pq.push(make_pair(min(a,b), max(a,b)));
        }
        
        tq.push(pq.top().second);
        pq.pop();
        
        int el;
        while(!pq.empty()){
            el = tq.top() & 1 ? tq.top()+1 : tq.top();
            if(pq.top().first > el){
                tq.pop();
                tq.push(pq.top().second);
                pq.pop();
            }else{
                tq.push(pq.top().second);
                pq.pop();
            }
        }
        
        cout << tq.size() << "\n";
    }
    return 0;
}
