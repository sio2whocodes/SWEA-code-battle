//
//  1461.cpp
//  swea
//
//  Created by 임수정 on 2021/08/01.
//


//if(hereR == N-1 || hereR == 0 || hereC == N-1 || hereC == 0){
//    //가장자리까지 옴
//    if(map[hereR][hereC] == 0){
//        Pos p = Pos();
//        p.r = hereR;
//        p.c = hereC;
//        lines.push_back(p);
//        isCon = true;
//        break;
//    }else{
//        isCon = false;
//        break;
//    }
//}else{
//    //가장자리 이전, 설치 가능한 곳
//    if(map[hereR][hereC] == 0){
//        Pos p = Pos();
//        p.r = hereR;
//        p.c = hereC;
//        lines.push_back(p);
//    }
//    //가장자리 이전, 설치 불가
//    else{
//        isCon = false;
//        lines.clear();
//        break;
//    }
//}
//for(int i = 0 ; i < lines.size() ; i++){
//    Pos p = lines[i];
//    map[p.r][p.c] = 2;
//    cnt++;
//}
//dfs(coreIdx+1, lineLen+cnt, cntConn+1);
//for(int i = 0 ; i < lines.size() ; i++){
//    Pos p = lines[i];
//    map[p.r][p.c] = 0;
//}
//lines.clear();

#include<iostream>
#include<vector>

using namespace std;

struct Pos{
    int r;
    int c;
};

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

int N;
int minLine = 144;
int maxConnect = 0;
vector<Pos> cores;
vector<Pos> lines;

int map[12][12];


void dfs(int coreIdx, int lineLen, int cntConn){
    if(coreIdx == cores.size()){
        if(cntConn > maxConnect){
            maxConnect = cntConn;
            minLine = lineLen;
        }else if (cntConn == maxConnect){
            minLine = min(lineLen, minLine);
        }
    }else{
        for(int i = 0 ; i < 4 ; i++){
            bool isCon = false;
            int thereR = cores[coreIdx].r;
            int thereC = cores[coreIdx].c;
            
            int cnt = 0;
            
            int hereR = cores[coreIdx].r;
            int hereC = cores[coreIdx].c;
            lines.clear();
            while(true){
                hereR += dr[i];
                hereC += dc[i];
                if(map[hereR][hereC] == 0){
                    cnt++;
                    if(hereR == N-1 || hereR == 0 || hereC == N-1 || hereC == 0){
                        isCon = true;
                        break;
                    }
                }else{
                    cnt = 0;
                    isCon = false;
                    break;
                }
            }
            if(isCon){
                //전선 모두 2로
                int r = thereR;
                int c = thereC;
                for(int j = 0 ; j < cnt ; j++){
                    r += dr[i];
                    c += dc[i];
                    map[r][c] = 2;
                }
                
                dfs(coreIdx+1, lineLen+cnt, cntConn+1);
                
                r = thereR;
                c = thereC;
                for(int j = 0 ; j < cnt ; j++){
                    r += dr[i];
                    c += dc[i];
                    map[r][c] = 0;
                }
                
            }
        }
        dfs(coreIdx+1, lineLen, cntConn);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        minLine = 144;
        maxConnect = 0;
        cores.clear();
        
        cin >> N;
        
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                cin >> map[i][j];
                if(map[i][j] == 1 && i > 0 && i < N-1 && j > 0 && j < N-1){
                    Pos p = Pos();
                    p.r = i;
                    p.c = j;
                    cores.push_back(p);
                }
            }
        }
        
        dfs(0,0,0);
        cout << "#" << test_case << " " << minLine << "\n";
        
        
    }
    return 0;
}
