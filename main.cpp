#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MIN = -1000000001;

struct Node{
    int val, ind, l, r;
    Node* left;
    Node* right;

    Node(int l, int r): l(l), r(r), val(0), ind(0), left(nullptr), right(nullptr){}
};


class SegmentTree{
    Node* root;
    vector<int> tree;

    pair<int, int> ans(Node* n, int l, int r){
        if(n->r <= l || n->l >= r) return {MIN, -1};
        if(n->r <= r && n->l >= l) return {n->val, n->ind};
        auto left = ans(n->left, l, r), right = ans(n->right, l, r);
        if(left.first < right.first){
            return right;
        }
        return left;
    }
public:
    SegmentTree(vector<int> &arr): tree(arr) {
        if(arr.empty()){
            root = nullptr;
        }else{
            root = build(0, arr.size());
        }
    }

    Node* build(int l, int r){
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

    pair<int, int> ans(int l, int r){
        return ans(root, l, r);
    }
};

int main() {

}