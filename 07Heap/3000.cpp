//
//  3000.cpp
//  swea
//
//  Created by 임수정 on 2021/08/12.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        priority_queue<int, vector<int>, greater<>> min_heap;
        priority_queue<int, vector<int>, less<>> max_heap;
        
        int n, a;
        cin >> n >> a;
    
        max_heap.push(a);
        
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            int in[2];
            cin >> in[0] >> in[1];
            for(int j = 0 ; j < 2 ; j++){
                if(in[j] < max_heap.top()){
                    max_heap.push(in[j]);
                }else{
                    min_heap.push(in[j]);
                }
                
                if(max_heap.size() - min_heap.size() == 2){
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                }else if(min_heap.size() - max_heap.size() == 2){
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }
            if(max_heap.size() == min_heap.size() || min_heap.size() < max_heap.size()){
                sum += max_heap.top() % 20171109;
            }else if(max_heap.size() < min_heap.size()){
                sum += min_heap.top() % 20171109;
            }
        }
        
        cout << "#" << test_case << " " << sum % 20171109 << "\n";
        
        
    }
    return 0;
}
