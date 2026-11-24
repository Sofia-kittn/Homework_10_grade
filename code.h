#pragma once

struct Node{
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

public:
    List();
    //очищает список и память(автоматически)
    ~List();

    //проверят пустой ли список
    bool is_empty();
    //кол-во элементов
    int len();

    //добавление элемента в конец
    void push_back(int val);
    //добавление элемента в начало
    void push_front(int val);
    //добавление элемента перед каким-то индексом
    void add_before(int i, int val);
    //добавление элемента после какого-то индексом
    void add_after(int i, int val);

    //замена значения элемента
    bool change(int i, int val);

    //удаление первого элемента
    bool del_first();
    //удаление последнего элемента
    bool del_last();
    //удаление элемента по индексу
    bool del_ind(int i);
    //удаление первого вхождения элемента с данным значением
    bool del_val(int val);
    //удаление всех элементов с данным значением
    bool del_all_val(int val);

    //проверка входит ли элемент в список
    bool is_in(int val, bool fromBegin = true);

    //нахождение максимального элемента
    int max();

    //очищает сипсок и осводождает память(по вызову)
    void clear();

    //выводит все элемента списка
    void print_elems();
};