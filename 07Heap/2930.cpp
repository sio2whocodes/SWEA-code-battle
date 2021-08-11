//
//  2930.cpp
//  swea
//
//  Created by 임수정 on 2021/08/11.
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
        priority_queue<int, vector<int>, less<int>> maxHeap;
        int n;
        cin >> n;
        
        int result[100001];
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            int op;
            cin >> op;
            if(op == 1){
                int x;
                cin >> x;
                maxHeap.push(x);
            }else{
                if(maxHeap.empty()){
                    result[cnt++] = -1;
                }else{
                    result[cnt++] = maxHeap.top();
                    maxHeap.pop();
                }
            }
        }
        
        cout << "#" << test_case << " ";
        for(int i = 0 ; i < cnt ; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
