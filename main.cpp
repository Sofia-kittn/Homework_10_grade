#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node* prev;

    Node(int value, Node* next, Node* prev): value(value), next(next), prev(prev){}
    Node(): value(0), next(nullptr), prev(nullptr){}
};

class Stack{
    Node* front;
    Node* tail;
    int size;

public:
    Stack(): front(nullptr), tail(nullptr), size(0){}

    bool is_empty(){
        return size == 0;
    }

    void add(int val){
        Node* elem = new Node(val, nullptr, tail);

        if(size == 0){
            front = elem;
        }else{
            tail->next = elem;
        }
        tail = elem;
        size++;
    }

    bool pop_st(){
        if(is_empty()){
            cout << "error pop_st" << endl;
            return false;
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

    int len(){
        return size;
    }

    int last_elem(){
        if(size == 0){
            cout << "error last_elem" << endl;
            return -987654321;
        }

        return tail->value;
    }

    void del_all(){
        while(!is_empty()){
            pop_st();
        }
    }

    ~Stack() {
        del_all();
    }
};

int main(){

}