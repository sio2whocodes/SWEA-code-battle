//
//  3304.cpp
//  swea
//
//  Created by 임수정 on 2021/07/26.
//

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        //init & input
        string a, b;
        cin >> a >> b;
        vector<vector<int>> dp(1001, vector<int>(1001, 0));
        
        //process
        for(int i = 0 ; i <= a.size() ; i++){
            dp[0][i] = dp[i][0] = 0;
        }
        
        for(int i = 1 ; i-1 < a.size() ; i++){
            for(int j = 1 ; j-1 < b.size() ; j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        
        //output
        cout << dp[a.size()][b.size()] << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
