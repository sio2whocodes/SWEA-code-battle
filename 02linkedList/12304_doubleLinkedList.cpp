//
//  12304_doubleLinkedList.cpp
//  swea
//
//  Created by 임수정 on 2021/07/22.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern int findNode(int data);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);
extern int getReversedList(int output[MAX_NODE]);

static void run() {
    while (1) {
        int cmd, data, num, cnt, i = 0;
        int output[MAX_NODE] = { 0 };

        scanf("%d", &cmd);
        switch (cmd) {
        case ADD_HEAD: // 1
            scanf("%d", &data);
            addNode2Head(data);
            break;
        case ADD_TAIL: // 2
            scanf("%d", &data);
            addNode2Tail(data);
            break;
        case ADD_NUM: // 3
            scanf("%d %d", &data, &num);
            addNode2Num(data, num);
            break;
        case FIND: // 4
            scanf("%d", &data);
            num = findNode(data);
            printf("%d\n", num);
            break;
        case REMOVE: // 5
            scanf("%d", &data);
            removeNode(data);
            break;
        case PRINT: // 6
            cnt = getList(output);
            while (cnt--)
                printf("%d ", output[i++]);
            printf("\n");
            break;
        case PRINT_REVERSE: // 7
            cnt = getReversedList(output);
            while (cnt--)
                printf("%d ", output[i++]);
            printf("\n");
            break;
        case END:
            return;
        }
    }
}

int main(void) {
    //setbuf(stdout, NULL);
    //freopen("dll_input.txt", "r", stdin);

//    int T;
//    scanf("%d", &T);
//    for (int t = 1; t <= T; t++) {
//        printf("#%d\n", t);
//        init();
//        run();
//        printf("\n");
//    }
    init();
    addNode2Head(3);
    addNode2Tail(4);
    addNode2Num(7, 4);
    addNode2Head(5);

    return 0;
}


//MARK:-USER CODE

#define MAX_NODE 10000

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
Node* tail;

Node* getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].prev = nullptr;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    head = getNode(-1);
    tail = getNode(-1);
    head->next = tail;
    tail->prev = head;
}

void addNode2Head(int data)
{
    Node* n = getNode(data);
    head->next->prev = n;
    n->next = head->next;
    head->next = n;
    n->prev = head;
    
    n = head;
    while(n->next != tail){
        cout << n->next->data << endl;
        n = n->next;
    }
    
}

void addNode2Tail(int data)
{
    Node* n = getNode(data);
    tail->prev->next = n;
    n->prev = tail->prev;
    tail->prev = n;
    n->next = tail;
}

void addNode2Num(int data, int num)
{
    Node* n = getNode(data);
    Node* ptr = head;
    for(int i = 1 ; i < num && ptr->next != tail ; i++){
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next->prev = n;
    ptr->next = n;
    n->prev = ptr;
}

int findNode(int data)
{
    int i = 0;
    Node* ptr = head;
    while(ptr->next != tail && ptr->next->data != data){
        ptr = ptr->next;
        i++;
    }
    return i;
}

void removeNode(int data)
{
    Node* ptr = head;
    while(ptr->next != tail && ptr->next->data != data){
        ptr = ptr->next;
    }
    if(ptr->data == data){
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
}

int getList(int output[MAX_NODE])
{
    Node* n = head;
    int cnt = 0;
    while(n->next != tail){
        output[cnt++] = n->next->data;
        n = n->next;
    }
    return cnt;
}

int getReversedList(int output[MAX_NODE])
{
    Node* n = tail;
    int cnt = 0;
    while(n->prev != head){
        output[cnt++] = n->prev->data;
        n = n->prev;
    }
    return cnt;
}
