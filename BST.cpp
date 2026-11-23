#include "BST.h"
#include <iostream>
#include <deque>

using namespace std;

Node::Node(int val): val(val), right(nullptr), left(nullptr){}

BinarySearchTree::BinarySearchTree(): head(nullptr), size(0) {}
BinarySearchTree::~BinarySearchTree(){
    delete head;
}

void BinarySearchTree::insert(int val) {
    Node *n = new Node(val);
    if (head == nullptr) {
        head = n;
        size++;
        return;
    }

    Node *cur = head;
    while (true) {
        if (cur->val > val) {
            if (cur->left == nullptr) {
                cur->left = n;
                size++;
                return;
            }
            cur = cur->left;
        } else if (cur->val < val) {
            if (cur->right == nullptr) {
                cur->right = n;
                size++;
                return;
            }
            cur = cur->right;
        } else return;
    }
}

bool BinarySearchTree::contains(int val){
    Node* cur = head;
    while(cur != nullptr && cur->val != val){
        if(cur->val > val){
            cur = cur->left;
        }else if(cur->val < val){
            cur = cur->right;
        }
    }
    if(cur) return true;
    return false;
}

void BinarySearchTree::erase(int val){
    if(head == nullptr){
        throw "error erase";
    }

    Node* cur = head;
    Node* pr = nullptr;
    while(cur && cur->val != val){
        pr = cur;
        if(cur->val > val){
            cur = cur->left;
        }else if(cur->val < val){
            cur = cur->right;
        }
    }
    if(!cur) return;

    if(cur->right && cur->left){
        Node* par = cur;
        Node* ncur = cur->right;
        while(ncur->left){
            par = ncur;
            ncur = ncur->left;
        }
        cur->val = ncur->val;
        pr = par;
        cur = ncur;
    }

    Node* child = cur->left;
    if(!child) child = cur->right;

    if(!pr) head = child;
    else if(pr->left == cur) pr->left = child;
    else pr->right = child;

    delete cur;
    size--;
}

void BinarySearchTree::print(){
    deque<Node*> st;
    Node* cur = head;

    while(cur != nullptr || !st.empty()){
        while(cur != nullptr){
            st.push_back(cur);
            cur = cur->left;
        }
        cur = st.back();
        st.pop_back();

        cout << cur->val << ' ';
        cur = cur->right;
    }
}

bool BinarySearchTree::empty(){
    if(head == nullptr) return true;
    return false;
}

int BinarySearchTree::whatSize(){
    return size;
}