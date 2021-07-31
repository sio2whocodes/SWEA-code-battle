//
//  1248.cpp
//  swea
//
//  Created by 임수정 on 2021/07/31.
//

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int find_common_parent(vector<int> p1l, vector<int> p2l){
    for(int i = 0 ; i < p1l.size() ; i++){
        for(int j = 0 ; j < p2l.size() ; j++){
            if(p1l[i] == p2l[j]){
                return p1l[i];
            }
        }
    }
    return 1;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int v, e, c1, c2;
        cin >> v >> e >> c1 >> c2;

        vector<vector<bool>> adj(v+1, vector<bool>(v+1, 0));
        vector<int> parent(v+1, 0);
        int p, c;
        for(int i = 0 ; i < e ; i++){
            cin >> p >> c;
            adj[p][c] = 1;
            parent[c] = p;
        }
        
        //공통조상 찾기
        vector<int> p1l, p2l;
        int rc = c1;
        while(rc != 1){
            p1l.push_back(parent[rc]);
            rc = parent[rc];
        }
        rc = c2;
        while(rc != 1){
            p2l.push_back(parent[rc]);
            rc = parent[rc];
        }
        
        int common_parent = find_common_parent(p1l, p2l);
        
        //서브트리 크기 구하기
        int sizeOfSubtree = 1;
        queue<int> parents;
        parents.push(common_parent);
        while(!parents.empty()){
            int currentParent = parents.front();
            parents.pop();
            for(int j = 1 ; j <= v ; j++){
                if(adj[currentParent][j]){
                    sizeOfSubtree++;
                    parents.push(j);
                }
            }
        }
        
        
        //output
        cout << "#" << test_case << " " << common_parent << " " << sizeOfSubtree << "\n";
        
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
