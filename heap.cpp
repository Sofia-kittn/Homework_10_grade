#include "heap.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Node::Node(int v): val(v){}
Node::Node(): val(0){}

void swap_v(Node* a, Node* b){
    int n = a->val;
    a->val = b->val;
    b->val = n;
}

Heap::Heap(): size(0), root(nullptr), last(nullptr){}
Heap::~Heap(){
    clear(root);
}

Node* Heap::find(int pos){
    if(pos < 1 || pos > size){
        throw "error find";
    }

    if(pos == 1) return root;

    vector<int> kids;
    while(pos > 1){
        kids.push_back(pos % 2);
        pos /= 2;
    }

    reverse(kids.begin(), kids.end());

    Node* cur = root;
    for(int i : kids){
        if(i == 0) cur = cur->left;
        else cur = cur->right;
    }
    return cur;
}

void Heap::insert(int val){
    Node* n = new Node(val);

    if(root == nullptr){
        root = n;
        last = root;
        size++;
        return;
    }

    int pos = size + 1;
    Node* prev = find(pos / 2);
    n->parent = prev;
    if(pos % 2 == 0) prev->left = n;
    else prev->right = n;
    size++;
    last = n;

    while(n->parent && n->parent->val < n->val){
        swap_v(n, n->parent);
        n = n->parent;
    }
}

int Heap::del_m(){
    if(!root){
        throw "error del_m heap is empty";
    }
    int ans = root->val;

    if(size == 1){
        delete root;
        root = nullptr;
        last = nullptr;
        size = 0;
        return ans;
    }
    size--;

    swap_v(root, last);
    Node* last_prev = last->parent;
    if(last_prev->left == last) last_prev->left = nullptr;
    else last_prev->right = nullptr;
    Node* del = last;
    last = find(size);
    delete del;

    Node* cur = root;
    while(cur->left != nullptr){
        Node* child = cur->left;
        if(cur->right != nullptr && cur->right->val > cur->left->val) child = cur->right;
        if(cur->val >= child->val) break;

        swap_v(cur, child);
        cur = child;
    }

    return ans;
}

bool Heap::empty(){
    return size == 0;
}

int Heap::get_m(){
    if(!root){
        throw "error get_m heap is empty";
    }
    return root->val;
}

int Heap::what_size() {
    return size;
}

void Heap::clear(Node* n) {
    if(!n)return;
    clear(n->right);
    clear(n->left);
    delete n;
}