#include "code.h"
#include <iostream>

using namespace std;

List::List(): head(nullptr), tail(nullptr), size(0){}
List::~List(){
    clear();
}

bool List::is_empty(){
    return size == 0;
}

int List::len(){
    return size;
}

void List::push_back(int val){
    Node* elem = new Node(val);

    if(is_empty()){
        head = elem;
        tail = elem;
    }else{
        elem->prev = tail;
        tail->next = elem;
        tail = elem;
    }
    size++;
}

void List::push_front(int val){
    Node* elem = new Node(val);

    if(is_empty()){
        head = elem;
        tail = elem;
    }else{
        elem->next = head;
        head->prev = elem;
        head = elem;
    }
    size++;
}

void List::add_before(int i, int val){
    if(i >= size || i < 0){
        throw "error add_before";
    }
    if(i == 0){
        push_front(val);
        return;
    }

    Node* elem = new Node(val);
    Node* cur = head;
    int ind = 0;

    while(cur){
        if(ind == i){
            elem->prev = cur->prev;
            elem->next = cur;
            cur->prev->next = elem;
            cur->prev = elem;
            size++;
            return;
        }
        ind++;
        cur = cur->next;
    }
}

void List::add_after(int i, int val){
    if(i >= size || i < 0){
        throw "error add_after";
    }
    if(i == size - 1){
        push_back(val);
        return;
    }

    Node* elem = new Node(val);
    Node* cur = head;
    int ind = 0;

    while(cur){
        if(ind == i){
            elem->next = cur->next;
            elem->prev = cur;
            cur->next->prev = elem;
            cur->next = elem;
            size++;
            return;
        }
        ind++;
        cur = cur->next;
    }
}

bool List::change(int i, int val){
    if(i >= size || i < 0){
        throw "error change";
    }

    Node* elem = head;
    int ind = 0;

    while(elem){
        if(ind == i){
            elem->value = val;
            return true;
        }
        ind++;
        elem = elem->next;
    }
    return false;
}

bool List::del_first(){
    if(size == 0){
        throw "error del_first";
    }

    Node* to_del = head;
    if(size == 1){
        head = nullptr;
        tail = nullptr;
    }else{
        head = head->next;
        head->prev = nullptr;
    }
    delete to_del;
    size--;
    return true;
}

bool List::del_last(){
    if(size == 0){
        throw "error del_last";
    }

    Node* to_del = tail;
    if(size == 1) {
        head = nullptr;
        tail = nullptr;
    }else{
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete to_del;
    size--;
    return true;
}

bool List::del_ind(int i){
    if(i >= size || i < 0){
        throw "error del_ind";
    }
    if(i == 0){
        del_first();
        return true;
    }else if(i == len() - 1){
        del_last();
        return true;
    }

    Node* to_del = head;
    int ind = 0;

    while(to_del){
        if(ind == i){
            to_del->next->prev = to_del->prev;
            to_del->prev->next = to_del->next;
            delete to_del;
            size--;
            return true;
        }
        ind++;
        to_del = to_del->next;
    }
    return false;
}

bool List::del_val(int val){
    Node* elem = head;
    int ind = 0;

    while(elem){
        if(elem->value == val){
            return del_ind(ind);
        }
        ind++;
        elem = elem->next;
    }
    return false;
}

bool List::del_all_val(int val){
    Node* elem = head;
    int ind = 0;
    bool is_del = false;

    while(elem){
        Node* cur = elem->next;
        if(elem->value == val){
            if(del_ind(ind)) is_del = true;
        }else ind++;
        elem = cur;
    }
    return is_del;
}

bool List::is_in(int val, bool fromBegin){
    if(fromBegin){
        Node* elem = head;
        while(elem){
            if(elem->value == val){
                return true;
            }
            elem = elem->next;
        }
    }else{
        Node* elem = tail;
        while(elem){
            if(elem->value == val){
                return true;
            }
            elem = elem->prev;
        }
    }
    return false;
}

int List::max(){
    if(size == 0){
        throw "error max";
    }

    int ans = head->value;
    Node* elem = head->next;
    while(elem) {
        if(elem->value > ans) ans = elem->value;
        elem = elem->next;
    }
    return ans;
}

void List::clear(){
    while(!is_empty()){
        del_last();
    }
}

void List::print_elems(){
    Node* elem = head;
    while(elem){
        cout << elem->value << '\n';
        elem = elem->next;
    }
    cout << '\n';;
}