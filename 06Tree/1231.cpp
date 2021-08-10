//
//  1231.cpp
//  swea
//
//  Created by 임수정 on 2021/08/10.
//

#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    char data;
    int left;
    int right;
};

void inorder_traverse(int here, Node* tree){
    if(here){
        inorder_traverse(tree[here].left, tree);
        cout << tree[here].data;
        inorder_traverse(tree[here].right, tree);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        
        Node tree[101];
        for (int i = 1; i <= n; i++) {
            Node node = Node();
            node.left = 0;
            node.right = 0;
            
            cin >> i >> tree[i].data;
            if (i < n / 2) {
                cin >> tree[i].left >> tree[i].right;
            } else if (i == n / 2) {
                cin >> tree[i].left;
                if (n & 1){
                    cin >> tree[i].right;
                }
            }
            
        }
        
        cout << "#" << test_case << " ";
        inorder_traverse(1, tree);
        cout << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
