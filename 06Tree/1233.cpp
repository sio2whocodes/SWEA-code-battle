//
//  1233.cpp
//  swea
//
//  Created by 임수정 on 2021/08/10.
//

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char** argv)
{
    int test_case;
    for(test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        cin >> n;
        
        int result = 1;
        for (int i = 1; i <= n; i++) {
            string data;
            cin >> i >> data;
            
            int left, right;
            if (i <= n / 2) {
                if (data[0] >= '0' && data[0] <= '9')
                    result = 0;
                if (i == n / 2 && !(n & 1) )
                    cin >> left;
                else
                    cin >> left >> right;
                
            } else {
                if (data[0] < '0' || data[0] > '9')
                    result = 0;
            }
        }
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
