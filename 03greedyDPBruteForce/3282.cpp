//
//  3282.cpp
//  swea
//
//  Created by 임수정 on 2021/07/27.
//

#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, capacity;
        cin >> N >> capacity;
        vector<vector<int>> dp(101, vector<int>(1001, 0));
        for(int i = 1 ; i <= N ; i++){
            int weight, value;
            cin >> weight >> value;
            for(int w = 0 ; w <= capacity ; w++){
                if(weight > w || value + dp[i-1][w-weight] < dp[i-1][w]){
                    dp[i][w] = dp[i-1][w];
                }else{
                    dp[i][w] = value + dp[i-1][w-weight];
                }
            }
        }
        cout << "#" << test_case << " " << dp[N][capacity] << "\n";
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
