//
//  1256.cpp
//  swea
//
//  Created by 임수정 on 2021/08/12.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ALPHABETS_CNT 27
#define MAXN 100000

struct Trie;
Trie* myAlloc();

struct Trie {
    Trie* _children[ALPHABETS_CNT];

    void add(const char* word) {
        if (*word != 0) {
            if(*word == '$'){
                _children[0] = myAlloc();
            }
            else{
                if (_children[*word - 'a' + 1] == nullptr)
                    _children[*word - 'a' + 1] = myAlloc();
                _children[*word - 'a' + 1]->add(word + 1);
            }
        }
    }

    Trie* get(const char* word) {
        if (*word != 0) {
            if(_children[0]){
                
            }
            if (_children[*word - 'a' + 1] != nullptr)
                return _children[*word - 'a' + 1]->get(word + 1);
            return nullptr;
        }
        return this;
    }

    void clear() {
        for (int i = 0; i < ALPHABETS_CNT; i++) {
            _children[i] = nullptr;
        }
    }
};

Trie Node[MAXN];
int nodeCnt = 0;
int k, cnt;
vector<char> v;

Trie* myAlloc() {
    Trie* ret = &Node[nodeCnt++];
    ret->clear();
    return ret;
}

void findKthSuffix(Trie* root){
    if(cnt == k){
        return;
    }
    if(root->_children[0]){
        if(++cnt == k){
            for(int i = 0 ; i < v.size() ; i++){
                cout << v[i];
            }
            cout << "\n";
            return;
        }
    }
    for(int i = 1 ; i <= 26 ; i++){
        if(root->_children[i]){
            v.push_back(i-1+'a');
            findKthSuffix(root->_children[i]);
            v.pop_back();
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int test_case = 1 ; test_case <= T ; test_case++){
        nodeCnt = 0;
        Trie* root = myAlloc();

        string s;
        cin >> k >> s;
        
        if(k > s.size()){
            cout <<"#" << test_case << " none\n";
            continue;
        }
        
        for(int i = 0 ; i < s.size() ; i++){
            string sufix = s.substr(i, s.size()-i) + "$";
            
            char sufixch[sufix.size()+1];
            for(int j = 0 ; j < sufix.size() ; j++){
                sufixch[j] = sufix[j];
            }
            sufixch[sufix.size()] = '\0';
            root->add(sufixch);
        }
        
        cnt = 0;
        cout << "#" << test_case << " ";
        findKthSuffix(root);
    }
    return 0;
}
