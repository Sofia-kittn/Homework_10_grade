#include <iostream>

using namespace std;

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
    List(): head(nullptr), tail(nullptr), size(0){}

    bool is_empty(){
        return size == 0;
    }

    int len(){
        return size;
    }

    void push_back(int val){
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

    void push_front(int val){
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

    void add_before(int i, int val){
        if(i >= size || i < 0){
            cout << "error add_before\n" << endl;
            return;
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

    void add_after(int i, int val){
        if(i >= size || i < 0){
            cout << "error add_after\n" << endl;
            return;
        }
        if(i == size - 1){
            push_back(val);
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

    bool change(int i, int val){
        if(i >= size || i < 0){
            cout << "error change\n" << endl;
            return false;
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

    bool del_first(){
        if(size == 0){
            cout << "error del_first\n" << endl;
            return false;
        }

        Node* to_del = head;
        if(size == 1){
            head = nullptr;
            tail = nullptr;
        }else{
            head = head->next;
            head->prev = tail;
        }
        delete to_del;
        return true;
    }

    bool del_last(){
        if(size == 0){
            cout << "error del_last\n" << endl;
            return false;
        }

        Node* to_del = head;
        if(size == 1) {
            head = nullptr;
            tail = nullptr;
        }else{
            tail = tail->prev;
            tail->next = head;
        }
        delete to_del;
        return true;
    }

    bool del_ind(int i){
        if(i >= size || i < 0){
            cout << "error del_ind\n" << endl;
            return false;
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
                return true;
            }
            ind++;
            to_del = to_del->next;
        }
        return false;
    }

    bool del_val(int val){
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

    bool del_all_val(int val){
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

    bool is_in(int val, bool fromBegin = true){
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

    int max(){
        if(size == 0){
            cout << "error_max\n";
            return INT_MIN;
        }

        int ans = head->value;
        Node* elem = head->next;
        while(elem) {
            if(elem->value > ans) ans = elem->value;
            elem = elem->next;
        }
        return ans;
    }

    void clear(){
        while(!is_empty()){
            del_last();
        }
    }

    void print_elems(){
        Node* elem = head;
        while(elem){
            cout << elem->value << '\n';
            elem = elem->next;
        }
        cout << '\n';;
    }
};

int main(){

}