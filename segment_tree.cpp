#include "segment_tree.h"
#include <iostream>
#include <vector>

using namespace std;

int MIN = -1000000001;

Node::Node(int l, int r): l(l), r(r), val(0), ind(0), left(nullptr), right(nullptr){}

SegmentTree::SegmentTree(vector<int> &arr): tree(arr) {
    if(arr.empty()){
        root = nullptr;
    }else{
        root = build(0, arr.size());
    }
}

SegmentTree::~SegmentTree(){
    clear(root);
}

void SegmentTree::clear(Node* n){
    if(!n) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

Node* SegmentTree::build(int l, int r){
    Node* n = new Node(l, r);
    if(r - l == 1){
        if(l >= tree.size()){
            n->val = MIN;
        }else{
            n->val = tree[l];
        }
        n->ind = l;
        return n;
    }

    int mid = (l + r) / 2;
    n->left = build(l, mid);
    n->right = build(mid, r);
    n->val = max(n->left->val, n->right->val);
    if(n->left->val >= n->right->val){
        n->ind = n->left->ind;
    }else{
        n->ind = n->right->ind;
    }
    return n;
}

pair<int, int> SegmentTree::ans(Node* n, int l, int r){
    if(n->r <= l || n->l >= r) return {MIN, -1};
    if(n->r <= r && n->l >= l) return {n->val, n->ind};
    auto left = ans(n->left, l, r), right = ans(n->right, l, r);
    if(left.first < right.first){
        return right;
    }
    return left;
}

pair<int, int> SegmentTree::ans(int l, int r){
    return ans(root, l, r);
}

void SegmentTree::change(Node *n, int ind, int val) {
    if (n->r - n->l == 1) {
        n->val = val;
        return;
    }

    int mid = (n->l + n->r) / 2;
    if (ind < mid) {
        change(n->left, ind, val);
    } else {
        change(n->right, ind, val);
    }

    n->val = max(n->left->val, n->right->val);
    if(n->left->val >= n->right->val){
        n->ind = n->left->ind;
    }else{
        n->ind = n->right->ind;
    }
}

void SegmentTree::change(int ind, int val) {
    if(!root) throw "error: can't change";
    if(ind < 0 || ind > tree.size()) throw "error invalid ind";

    tree[ind] = val;
    change(root, ind, val);
}