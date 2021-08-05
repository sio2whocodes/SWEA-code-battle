//
//  1855.cpp
//  swea
//
//  Created by 임수정 on 2021/08/05.
//

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
vector<vector<int>> adj(100005);
int parents[100005][23];
int depths[100005];
queue<int> q;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
//        memset(check,0,sizeof(check));
        memset(depths,0,sizeof(depths));
        memset(parents,0,sizeof(parents));
        adj.clear();
        
        cin >> N;
        adj.resize(N+5);
        
        parents[1][0] = 0;
        depths[1] = 0;
        for(int i = 2 ; i <= N ; i++){
            cin >> parents[i][0];
            adj[parents[i][0]].push_back(i);
            depths[i] = depths[parents[i][0]]+1;
        }
        
        for (int i = 1; i <= 18; i++) {
            for (int n = 1; n <= N; n++) {
                int tparent = parents[n][i-1];
//                cout << tparent << endl;
                parents[n][i] = parents[tparent][i-1];
            }
        }
        
        //공통 조상 && bfs
        int result = 0;
        queue<int> tq;
        q.push(1);
        while(!q.empty()){
            int parent = q.front();
            q.pop();
            tq.push(parent);
            if(tq.size() == 2){
                //두 노드의 공통 조상 계산(간선 수 계산)
                int a = tq.front();
                int b = tq.back();
                
                int cnt = depths[a] + depths[b];

                if(depths[a] < depths[b]){
                    int temp = a;
                    a = b;
                    b = temp;
                }
                
                for (int i = 18; i >= 0; i--) {
                    long dif = depths[a] - depths[b];
                    if (dif >= (1 << i)) {
                        a = parents[a][i];
                    }
                }
                
                int lca = 1;
                if(a == b){
                    lca = a;
                }else{
                    for (int i = 18; i >= 0; i--) {
                        if (parents[a][i] != parents[b][i]) {
                            a = parents[a][i];
                            b = parents[b][i];
                        }
                    }
                    lca = parents[a][0];
                }
                
                
                
                cnt -= 2 * depths[lca];
                tq.pop();
                result += cnt;
            }
            for(int i = 0 ; i < adj[parent].size() ; i++){
                q.push(adj[parent][i]);
            }
        }
        
        cout << "#" << test_case << " " << result << "\n";
        
    }
    return 0;
}
