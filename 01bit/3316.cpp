//
//  3316.cpp
//  swea
//
//  Created by 임수정 on 2021/07/20.
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
        //input
        char day[10001];
        cin >> day;
        cout << day[0] << endl;
        
        //process
        int poss[16][2];
        poss[0][0] = 0;
        for(int i = 1 ; i <= 15 ; i++){
            if((i & (8 | (1 << (day[0]-'A')))) == (8 | (1 << (day[0]-'A')))){
                poss[i][0] = 1;
            }else{
                poss[i][0] = 0;
            }
            poss[i][1] = 0;
            cout << poss[i][0] << endl;
        }
        cout << endl;
        
        int i = 1;
        while(day[i] != '\0'){
            for(int j = 1 ; j <= 15 ; j++){
                poss[j][1] = 0;
                if(j & (1 << (day[i]-'A'))){
                    for(int p = 1 ; p <= 15 ; p++){
                        if(j & p){
                            cout << j << "&" << p << endl;
                            poss[j][1] += poss[p][0]%1000000007;
                            cout <<"!"<<poss[j][1] << endl;
                        }
                    }
                }
            }
            for(int k = 1 ; k <= 15 ; k++){
                poss[k][0] = poss[k][1];
                cout << poss[k][0] << "," << poss[k][1] << endl;
            }
            cout << endl;
            i++;
        }
        
        //output
        int result = 0;
        for(int i = 1 ; i <= 15 ; i++){
            result += poss[i][0];
            cout << poss[i][0] << endl;
        }
        cout << result%1000000007 << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
