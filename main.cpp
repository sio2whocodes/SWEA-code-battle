//
//  main.cpp
//  swea
//
//  Created by 임수정 on 2021/07/20.
//
/*
#define MAX_NODE 10000

struct Node {
    int data;
    Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    head = getNode(-1);
}

void addNode2Head(int data)
{
    Node* n = getNode(data);
    n->next = head->next;
    head->next = n;
}

void addNode2Tail(int data)
{
    Node* n = getNode(data);
    Node* ptr = head;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = n;
}

void addNode2Num(int data, int num)
{
    Node* n = getNode(data);
    Node* ptr = head;
    for(int i = 1 ; i < num && ptr->next ; i++){
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next = n;
}

void removeNode(int data)
{
    Node* n = head;
    while(n->next && n->next->data != data){
        n = n->next;
    }
    n->next = n->next->next;
}

int getList(int output[MAX_NODE])
{
    Node* n = head;
    int cnt = 0;
    while(n->next){
        output[cnt++] = n->next->data;
        n = n->next;
    }
    return cnt;
}*/
