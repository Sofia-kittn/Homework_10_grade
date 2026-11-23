#pragma once

struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val);
};

class BinarySearchTree {
    Node *head;
    int size;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    //обавить элемент
    void insert(int val);

    //проверить содержится ли элемент
    bool contains(int val);

    //удалить элемент по значению
    void erase(int val);

    //вывод всех элементов дерева по возрастанию
    void print();

    //проверка пустоты дерева
    bool empty();

    //узнать кол-во элементов в дереве
    int whatSize();
};