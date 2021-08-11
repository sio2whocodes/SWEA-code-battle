//
//  12372.cpp
//  swea
//
//  Created by 임수정 on 2021/08/11.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_INPUT 10000
#define MAX_NUM 30000

extern void init();
extern void addUser(int uID, int income);
extern int getTop10(int result[10]);

static int input[MAX_INPUT];

static unsigned int seed = 13410;

static unsigned int pseudoRand() {
    seed = seed * 214013 + 2531011;
    return (unsigned int)(seed >> 11) % MAX_NUM;
}

static void makeInput(int inputLen) {
    for (int i = 0; i < inputLen; i++) {
        input[i] = pseudoRand();
    }
}

static int run() {
    int N, userNum, uID = 0;
    int score = 100, result[10], cnt;
    int sum, check;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &userNum);
        makeInput(userNum);
        for (int j = 0; j < userNum; j++) {
            addUser(uID++, input[j]);
        }
        cnt = getTop10(result);

        sum = 0;
        for (int j = 0; j < cnt; j++)
            sum += result[j];
        scanf("%d", &check);
        if (check != sum)
            score = 0;
    }
    return score;
}

int main(void) {
    setbuf(stdout, NULL);
    //freopen("partial_sort_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        init();
        printf("#%d %d\n", tc, run());
    }
    return 0;
}

struct User{
    int uId;
    int income;
};

User heap[MAX_INPUT];
int heapSize = 0;
void init()
{
    heapSize = 0;
}

void addUser(int uID, int income)
{
    if (heapSize + 1 > MAX_INPUT) {
        return;
    }

    heap[heapSize].uId = uID;
    heap[heapSize].income = income;
    // 마지막 노드에 값 추가

    // 마지막 노드에 추가한 값을 올바른 위치로 옮긴다
    int current = heapSize;
    
    //반복문 진입 조건 : 현재 위치가 올바른 위치가 아닐 떄
    //힙이 비어있지 않는 경우 (비어있다면 현재 자리(루트 노드)가 올바른 위치)
    //본인 보다 부모가 값이 더 작은 경우 (최대힙)
    while (current > 0 && (heap[current].income > heap[(current - 1) / 2].income || (heap[current].income == heap[(current - 1) / 2].income && heap[current].uId < heap[(current - 1) / 2].uId))) {
        // 부모와 자식의 우선순위 비교
        // 자식의 우선순위가 더 높으면 부모와 값을 바꿔준다
        int tempUId = heap[(current - 1) / 2].uId;
        int tempIncome = heap[(current - 1) / 2].income;
        heap[(current - 1) / 2].income = heap[current].income;
        heap[(current - 1) / 2].uId = heap[current].uId;
        heap[current].income = tempIncome;
        heap[current].uId = tempUId;

        current = (current - 1) / 2;
    }

    heapSize = heapSize + 1;
}

int heapPop() {
    if (heapSize <= 0)
        return -1;

    int value = heap[0].uId;
    heapSize = heapSize - 1;
    heap[0].uId = heap[heapSize].uId;
    heap[0].income = heap[heapSize].income;
    // 마지막 data를 root에 저장

    // root에 저장된 값을 올바른 위치로 옮긴다
    int current = 0;

    //본인의 자식이 있는 경우만 들어감
    while (current * 2 + 1 < heapSize) { //적어도 왼쪽 자식 하나는 있음
        int child;
        if (current * 2 + 2 == heapSize) //오른쪽 자식 없음
            child = current * 2 + 1;
        else{ //오른쪽 자식도 있음 -> 자식 중 큰 걸로 교체 준비 //uId가 이른순으로 -> >=
            if(heap[current * 2 + 1].income > heap[current * 2 + 2].income){
                child = current * 2 + 1;
            }else if(heap[current * 2 + 1].income == heap[current * 2 + 2].income){
                child = heap[current * 2 + 1].uId < heap[current * 2 + 2].uId ? current * 2 + 1 : current * 2 + 2;
            }else{
                child = current * 2 + 2;
            }
            
        }
        //현재 위치가 올바른 위치이면 반복문 탈출(최대힙)
        if(heap[current].income > heap[child].income)
            break;
        else if(heap[current].income == heap[child].income && heap[current].uId < heap[child].uId){
            break;
        }
        //자식 중 큰 노드랑 교체
        int tempUId = heap[current].uId;
        int tempIncome = heap[current].income;
        heap[current].uId = heap[child].uId;
        heap[current].income = heap[child].income;
        heap[child].uId = tempUId;
        heap[child].income = tempIncome;
        current = child;
    }
    //아까 빼둔 루트노드 값 반환
    return value;
}
int getTop10(int result[10])
{
    int cnt = 0;
    int sum = 0;
    for(int i = 0 ; i < 10 ; i++){
        int pop = heapPop();
        if(pop == -1){
            break;
        }else{
            result[i] = pop;
            sum += pop;
            cnt++;
        }
    }
    printf("sum : %d\n", sum);
    return cnt;
}
