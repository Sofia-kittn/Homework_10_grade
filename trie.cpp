#include "trie.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

Node::Node(int v): val(v), children(vector<Node*>(26, nullptr)){}
Node::Node(): val(' '), children(vector<Node*>(26, nullptr)){}

void Trie::lex(Node* cur, string& pref, vector<string>& words){
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

Trie::Trie(): root(new Node){}
Trie::~Trie() {
    clear(root);
}

void Trie::clear(Node *n) {
    if(!n) return;

    for(auto i: n->children){
        clear(i);
    }
    delete n;
}

void Trie::insert(string& word){
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

bool Trie::contains(string& word){
    Node* cur = root;
    for(char c : word) {
        if(cur->children[int(c - 'a')] == nullptr){
            return false;
        }
        cur = cur->children[int(c - 'a')];
    }
    return cur->is_end;
}

bool Trie::starts_with(string& pref){
    Node* cur = root;
    for(char c : pref) {
        if(cur->children[int(c - 'a')] == nullptr){
            return false;
        }
        cur = cur->children[int(c - 'a')];
    }
    return true;
}

vector<string> Trie::sort_words(){
    vector<string> words;
    string pref;
    lex(root, pref, words);
    return words;
}
