//
//  4408.cpp
//  swea
//
//  Created by 임수정 on 2021/07/24.
//

#include<iostream>
using namespace std;

struct Map{
    int s;
    int e;
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
        
        Map arr[N];
        bool visit[N];

        int a,b;
        for(int i = 0 ; i < N ; i++){
            cin >> a >> b;
            arr[i].s = min(a,b);
            arr[i].e = max(a,b);
            visit[i] = 0;
        }
        
        int cnt = 0;
        for(int i = 0 ; i < N ; i++){
            if(!visit[i]){
                cnt++;
            }
            int sl = arr[i].s & 1 ? arr[i].s : arr[i].s-1;
            int el = arr[i].e & 1 ? arr[i].e+1 : arr[i].e;
            for(int j = i+1 ; j < N ; j++){
                //이전 구간
                if(arr[j].e < sl){
                    visit[j] = 1;
                }
                //이후 구간
                else if(arr[j].s > el){
                    visit[j] = 1;
                }
            }
        }
        
        cout << cnt << "\n";
    }
    return 0;
}
