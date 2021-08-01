//
//  12318.cpp
//  swea
//
//  Created by 임수정 on 2021/07/31.
//
#include<iostream>
using namespace std;

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void bfs_init(int N, int map[10][10]);
extern int bfs(int x1, int y1, int x2, int y2);

static int test_bfs() {
    int N;
    int map[10][10];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    bfs_init(N, map);
    int M;
    int score = 100;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int result = bfs(x1, y1, x2, y2);
        int dist;
        scanf("%d", &dist);
        if (result != dist) score = 0;
    }
    return score;
}

int main() {
    setbuf(stdout, NULL);

    printf("#total score : %d\n", test_bfs());

    return 0;
}

int Map[11][11];
int n;

void bfs_init(int N, int map[10][10]){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            Map[i][j] = map[i-1][j-1];
        }
    }
    n = N;
}

struct Pos{
    int x;
    int y;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(int x1, int y1, int x2, int y2){
    int distance[11][11];
    for(int i = 0 ; i < 11 ; i++){
        for(int j = 0 ; j < 11 ; j++){
            distance[i][j] = -1;
        }
    }
    
    Pos q[100];
    int s,e;
    s = 0;
    e = 1;
    q[s] = Pos();
    q[s].x = x1;
    q[s].y = y1;
    distance[y1][x1] = 0;
    
    while(s<e){
        Pos here = q[s++];
        if(here.x == x2 && here.y == y2){
            break;
        }
        for(int i = 0 ; i < 4 ; i++){
            int cc = here.x+dx[i];
            int cr = here.y+dy[i];
            if(cr >= 1 && cc >= 1 && cr <= n && cc <= n && Map[cr][cc] == 0 && distance[cr][cc] == -1){
                distance[cr][cc] = distance[here.y][here.x] + 1;
                Pos newPos = Pos();
                newPos.x = cc;
                newPos.y = cr;
                q[e++] = newPos;
            }
        }
    }
    return distance[y2][x2];
}
