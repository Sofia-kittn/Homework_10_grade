#pragma once

struct Node{
    int value;
    Node* next;
    Node* prev;

    Node(int value, Node* next, Node* prev);
    Node();
};

class Stack{
    Node* front;
    Node* tail;
    int size;

public:
    Stack();
    //очищает стэк и память
    ~Stack();

    //проверка пустой ли стэк
    bool is_empty();

    //добавление элемента в стэк
    void add(int val);

    //удаление элемента из стэка
    bool pop_st();

    //кол-во элементов в стэке
    int len();

    //последний элемент
    int last_elem();

    //удаление всех элементов из стэка
    void del_all();
};
