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

    //поиск узла по позиции
    Node* find(int pos);

    //очищение кучи
    void clear(Node*);
public:
    Heap();
    ~Heap();

    //обавление элемента
    void insert(int val);

    //удаление max/min элемента
    int del_m();

    //взятие max/min элемента
    int get_m();

    //проверка пустоты
    bool empty();

    //проверка размера кучи
    int what_size();
};