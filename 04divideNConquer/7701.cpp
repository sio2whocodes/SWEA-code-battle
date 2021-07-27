//
//  7701.cpp
//  swea
//
//  Created by 임수정 on 2021/07/27.
//

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(string a, string b){
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {

        int N;
        cin >> N;
        vector<string> v(N);
        for(int i = 0 ; i < N ; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end(), cmp);
        
        cout << "#" << test_case << "\n";
        cout << v[0] << "\n";
        for(int i = 1 ; i < N ; i++){
            if(v[i-1] != v[i])
                cout << v[i] << "\n";
        }
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
