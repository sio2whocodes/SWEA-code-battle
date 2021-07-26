//
//  1288.cpp
//  swea
//
//  Created by 임수정 on 2021/07/20.
//

#include<iostream>
#include<bitset>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int org;
        cin >> org;
        int check = 0;
        int N = org;
        while(true){
            int m = N;
            cout << m << endl;
            while(m != 0){
                check |= (1 << (m % 10));
                cout << bitset<10>(1 << (m % 10)) << endl;
                cout << "check : "<<bitset<10>(check) << endl;
                m /= 10;
            }
            if(check == 0b1111111111) break;
            N += org;
        }
        cout << endl;
        cout << N << "\n";


    }
    return 0;
}
