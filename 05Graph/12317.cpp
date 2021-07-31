//
//  12317.cpp
//  swea
//
//  Created by 임수정 on 2021/07/31.
//
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
using namespace std;

static unsigned int seed = 12345;
static unsigned int pseudo_rand(int max) {
    seed = ((unsigned long long)seed * 1103515245 + 12345) & 0x7FFFFFFF;
    return seed % max;
}

#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)

extern void dfs_init(int N, int path[MAX_N][2]);
extern int dfs(int k);

static int p[MAX_K+2];
static int c[MAX_K+2];
static int path[MAX_N][2];
static void makeTree(int n) {
    for (int i = 1; i < MAX_K+2; ++i) {
        p[i] = c[i] = -1;
    }
    c[pseudo_rand(MAX_K + 1) + 1] = 0;
    for (int i = 0; i < n; ++i) {
        int pi = pseudo_rand(MAX_K + 1) + 1;
        while (c[pi] < 0 || c[pi] >= MAX_CHILD) {
            ++pi;
            if (pi == MAX_K + 2)
                pi = 1;
        }
        int ci = pseudo_rand(MAX_K + 1) + 1;
        while (c[ci] >= 0) {
            ++ci;
            if (ci == MAX_K + 2)
                ci = 1;
        }
        p[ci] = pi;
        ++c[pi];
        c[ci] = 0;
    }
    bool check[MAX_K + 2] = { false };
    for (int i = 0; i < n; ++i) {
        int e = pseudo_rand(MAX_K + 1) + 1;
        while (check[e] || c[e] < 0 || p[e] == -1) {
            ++e;
            if (e == MAX_K + 2)
                e = 1;
        }
        check[e] = true;
        path[i][0] = p[e];
        path[i][1] = e;
    }
}

int main() {
    setbuf(stdout, NULL);
    int T;
    //freopen("dfs_input.txt", "r", stdin);
    scanf("%d", &T);

    int totalScore = 0;
    for (int tc = 1; tc <= T; tc++) {
        int n, q;

        scanf("%d %d %d", &n, &q, &seed);

        makeTree(n - 1);
        dfs_init(n, path);

        bool check[MAX_K + 2] = { false };
        int score = 100;
        for (int i = 0; i < q; ++i) {
            int k, ret, correct;

            scanf("%d", &k);

            ret = dfs(k);
            cout << "ret"<< ret << "\n";
            scanf("%d", &correct);

            if (ret != correct)
                score = 0;
        }
        printf("#%d : %d\n", tc, score);
        totalScore += score;
    }
    printf("#total score : %d\n", totalScore / T);

    return 0;
}

int childList[100][5];
int childCnt[100];
int visit[100];

void dfs_init(int N, int path[100][2])
{
    for(int i = 0 ; i < 100 ; i++){
        childCnt[i] = 0;
    }
    
    for(int i = 0 ; i < N-1 ; i++){
        childList[path[i][0]][childCnt[path[i][0]]++] = path[i][1];
    }
    
//    for(int i = 0 ; i < N-1 ; i++){
//        cout << path[i][0] << " " << path[i][1] << "\n";
//    }
    
    
}

int result = -1;

void dfs2(int n, int origin){
    if(n > origin){
//        cout << n << "\n";
        if(result == -1){
            result = n;
        }
        return;
    }else{
        visit[n] = true;
        for(int i = 0 ; i < childCnt[n] ; i++){
            if(!visit[childList[n][i]]){
                dfs2(childList[n][i], origin);
            }
        }
    }
}


int dfs(int n)
{
    result = -1;
    for(int i = 0 ; i < 100 ; i++){
        visit[i] = 0;
    }
    dfs2(n,n);
//    cout << result << endl;
    return result;
}
