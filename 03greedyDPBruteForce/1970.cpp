//
//  1970.cpp
//  swea
//
//  Created by 임수정 on 2021/07/24.
//

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        
        cout << "#" << test_case << "\n";
        cout << N / 50000 << " ";
        N %= 50000;
        cout << N / 10000 << " ";
        N %= 10000;
        cout << N / 5000 << " ";
        N %= 5000;
        cout << N / 1000 << " ";
        N %= 1000;
        cout << N / 500 << " ";
        N %= 500;
        cout << N / 100 << " ";
        N %= 100;
        cout << N / 50 << " ";
        N %= 50;
        cout << N / 10 << " ";
    }
    return 0;
}
