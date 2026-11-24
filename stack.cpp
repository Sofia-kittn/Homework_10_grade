#include "stack.h"
#include <iostream>

using namespace std;

Node::Node(int value, Node* next, Node* prev): value(value), next(next), prev(prev){}
Node::Node(): value(0), next(nullptr), prev(nullptr){}

Stack::Stack(): front(nullptr), tail(nullptr), size(0){}
Stack::~Stack() {
    del_all();
}

bool Stack::is_empty(){
    return size == 0;
}

void Stack::add(int val){
    Node* elem = new Node(val, nullptr, tail);

    if(size == 0){
        front = elem;
    }else{
        tail->next = elem;
    }
    tail = elem;
    size++;
}

bool Stack::pop_st(){
    if(is_empty()){
        throw "error pop_st";
    }

    Node* to_del = tail;
    if(size == 1){
        front = nullptr;
        tail = nullptr;
    }else{
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete to_del;
    size--;
    return true;
}

int Stack::len(){
    return size;
}

int Stack::last_elem(){
    if(size == 0){
        throw "error last_elem";
    }

    return tail->value;
}

void Stack::del_all(){
    while(!is_empty()){
        pop_st();
    }
}