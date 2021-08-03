//
//  1868.cpp
//  swea
//
//  Created by 임수정 on 2021/08/03.
//

#include<iostream>
using namespace std;

int N;

int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};

int mine[300][300]; //-1:지뢰, 0:지뢰0, n:지뢰n개
char map[300][300]; //.: 미방문 땅, *:지뢰, 숫자:방문 땅

int countMine(int r, int c){
    //현재 위치가 지뢰
    if(map[r][c] == '*'){
        return -1;
    }
    
    //현재 위치가 지뢰 X
    int cnt = 0;
    for(int i = 0 ; i < 8 ; i++){
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr >= 0 && nc >= 0 && nr < N && nc < N){
            if(map[nr][nc] == '*'){
                cnt++;
            }
        }
    }
    return cnt;
}

void click(int r, int c){
    if(mine[r][c] > 0){
        map[r][c] = mine[r][c] + '0';
    }
    //지뢰 0
    else{
        map[r][c] = '0';
        for(int i = 0 ; i < 8 ; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr >= 0 && nc >= 0 && nr < N && nc < N && map[nr][nc] == '.'){
                click(nr, nc);
            }
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        //map 입력
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                cin >> map[i][j];
            }
        }
        //mine map 계산
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                mine[i][j] = countMine(i,j);
//                cout << mine[i][j] << " ";
            }
            cout << endl;
        }
        
        //0인곳 클릭
        int cnt = 0;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(mine[i][j] == 0 && map[i][j] == '.'){
                    click(i,j);
                    cnt++;
                }
            }
        }
        
        //남은 땅 클릭
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(map[i][j] == '.'){
                    click(i,j);
                    cnt++;
                }
            }
        }
        
        //output
        cout << "#" << test_case << " " << cnt << "\n";
        
    }
    return 0;
}
