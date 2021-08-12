//
//  1256-1.cpp
//  swea
//
//  Created by 임수정 on 2021/08/12.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int test_case;
    int T;
    cin >> T;
    
    for(test_case = 1; test_case <= T; ++test_case){
        string s;
        int k;
        cin >> k >> s;
        
        if(k > s.size()){
            cout << "#" << test_case << " none\n";
            continue;
        }
        
        string sufix[s.size()];
        for(int i = 0 ; i < s.size() ; i++){
            sufix[i] = s.substr(i, s.size()-i);
        }
        
        sort(sufix, sufix+s.size());
        cout << "#" << test_case << " " <<sufix[k-1] << "\n";
        
    }

    
    return 0;
}
