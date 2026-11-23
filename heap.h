#pragma once

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;

    Node(int v);
    Node();
};

void swap_v(Node* a, Node* b);

class Heap{
    Node* root = nullptr;
    Node* last = nullptr;
    int size = 0;

    Node* find(int pos);
public:
    Heap();
    ~Heap();

    //
    void insert(int val);

    //
    int del_m();

    //
    int get_min();

    //
    bool empty();
};