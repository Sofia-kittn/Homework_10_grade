#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    bool is_end = false;
    vector<Node*> children;
    int cnt_v = 0;

    Node(int v): val(v), children(vector<Node*>(26, nullptr)){}
    Node(): val(' '), children(vector<Node*>(26, nullptr)){}
};

class Trie{
    Node* root;

    void lex(Node* cur, string& pref, vector<string>& words){
        if(cur->is_end) {
            for(int i = 0; i < cur->cnt_v; i++) words.push_back(pref);
        }

        for(int i = 0; i < 26; i++){
            if(cur->children[i] != nullptr){
                pref += char('a' + i);
                lex(cur->children[i], pref, words);
                pref.pop_back();
            }
        }
    }

public:
    Trie(): root(new Node){}
    ~Trie() {delete root;}

    void insert(string& word){
        Node* cur = root;

        for(char c : word) {
            if(cur->children[int(c - 'a')] == nullptr){
                cur->children[int(c - 'a')] = new Node(c);
            }
            cur = cur->children[int(c - 'a')];
        }
        cur->is_end = true;
        cur->cnt_v++;
    }

    bool contains(string& word){
        Node* cur = root;
        for(char c : word) {
            if(cur->children[int(c - 'a')] == nullptr){
                return false;
            }
            cur = cur->children[int(c - 'a')];
        }
        return cur->is_end;
    }

    bool starts_with(string& pref){
        Node* cur = root;
        for(char c : pref) {
            if(cur->children[int(c - 'a')] == nullptr){
                return false;
            }
            cur = cur->children[int(c - 'a')];
        }
        return true;
    }

    vector<string> sort_words(){
        vector<string> words;
        string pref;
        lex(root, pref, words);
        return words;
    }
};

int main(){
}