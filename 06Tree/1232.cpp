//
//  1232.cpp
//  swea
//
//  Created by 임수정 on 2021/08/10.
//

#include <iostream>
#include <string>
using namespace std;

// + : -7 , - : -5 , * : -8, / : -3

struct Node{
    int data;
    int left;
    int right;
};

double prorder_traverse(int here, Node* tree){
    if(tree[here].data < 0){
        switch (tree[here].data) {
            case -7:
                return prorder_traverse(tree[here].left, tree) + prorder_traverse(tree[here].right, tree);
                break;
            case -5:
                return prorder_traverse(tree[here].left, tree) - prorder_traverse(tree[here].right, tree);
                break;
            case -8:
                return prorder_traverse(tree[here].left, tree) * prorder_traverse(tree[here].right, tree);
                break;
            case -3:
                double result = prorder_traverse(tree[here].left, tree) / prorder_traverse(tree[here].right, tree);
                return result;
                break;
        }
    }else{
        return tree[here].data;
    }
    return 0;
}

int main(int argc, char** argv)
{
    int test_case;
    for(test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        cin >> n;
        
        Node tree[1001];
        for (int i = 1; i <= n; i++) {
            string data;

            cin >> i >> data;
            tree[i].left = 0;
            tree[i].right = 0;
            if(data[0] >= '1' && data[0] <= '9'){
                tree[i].data = stoi(data);
            }else{
                tree[i].data = data[0]-50;
                cin >> tree[i].left >> tree[i].right;
            }
            
//            cout << tree[i].data << " " << tree[i].left << " " << tree[i].right << "\n";
            
            
        }
        int result = prorder_traverse(1, tree);
        cout << "#" << test_case << " " << result << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
