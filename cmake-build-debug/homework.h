#pragma once

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int value): value(value), next(nullptr), prev(nullptr){}
    Node(): value(0), next(nullptr), prev(nullptr){}
};

class List{
    Node* head;
    Node* tail;
    int size;


};