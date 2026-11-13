#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Inventory{
    set<string> items;
    map<string, int> cnt;

    void p_addItem(string name, int count){
        if(cnt[name] == 0){
            items.insert(name);
        }
        cnt[name] += count;
    }

    bool p_removeItem(string name, int count){
        if(cnt[name] < count) return false;
        if(cnt[name] == count){
            items.erase(name);
            cnt[name] = 0;
        }
        cnt[name] -= count;
        return true;
    }

    int p_getCount(string name){
        return cnt[name];
    }

public:
    Inventory(): cnt(), items(){}

    void print(){
        for(string name : items){
            cout << name << ' ';
        }
    }

    void addItem(string name, int count){
        p_addItem(name, count);
    }
    bool removeItem(string name, int count){
        return p_removeItem(name, count);
    }

    int getCount(string name){
        return p_getCount(name);
    }

    ~Inventory(){}
};


int main() {

}