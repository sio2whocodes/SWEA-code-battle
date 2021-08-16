//
//  2948.cpp
//  swea
//
//  Created by 임수정 on 2021/08/16.
//
//https://sio2whocode.tistory.com/142

#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        unordered_set<string> hash_set;
        int an, bn;
        cin >> an >> bn;
        for(int i = 0 ; i < an ; i++){
            char ch[51];
            cin >> ch;
            hash_set.emplace(string(ch));
        }
        
        int cnt = 0;

        for(int i = 0 ; i < bn ; i++){
            char ch[51];
            cin >> ch;
            hash_set.find(string(ch)) == hash_set.end() ? : cnt++;
        }
        cout << "#" << test_case << " " << cnt << "\n";
    }
    return 0;
}
