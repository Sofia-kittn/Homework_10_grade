#pragma once
#include <vector>

using namespace std;

struct Node{
    int val, ind, l, r;
    Node* left;
    Node* right;

    Node(int l, int r);
};

class SegmentTree{
    Node* root;
    vector<int> tree;

    //построение дерева рекурсивно
    Node* build(int l, int r);

    //нахождение ответа(внури для приватности)
    pair<int, int> ans(Node* n, int l, int r);

    //удаление элементов
    void clear(Node* n);

    //меняем значение элемента внутри
    void change(Node* n, int ind, int val);

public:
    SegmentTree(vector<int> &arr);
    ~SegmentTree();

    //нахождение ответа для пользователя
    pair<int, int> ans(int l, int r);

    //меняем значение элемента снаружи
    void change(int ind, int val);
};