#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Node{
    int val;

    Node(): val(0){}
    Node(int val): val(0){}
};

class Heap{
    vector<Node> arr;
    int size = 0;

public:
    void insert(Node& val){
        int i = size;
        arr.push_back(val);
        size++;
        while(i >= 1 && arr[i].val < arr[(i - 1) / 2].val){
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int del_m(){
        int ans = arr[0].val;
        size--;
        swap(arr[0], arr[size]);
        arr.resize(size);
        int i = 0;

        while(i * 2 + 1 < size){
            int cur = i * 2 + 1;

            if(i * 2 + 2 < size && arr[i * 2 + 2].val < arr[i * 2 + 1].val) cur = i * 2 + 2;
            if(arr[i].val <= arr[cur].val) break;

            swap(arr[i], arr[cur]);
            i = cur;
        }
        return ans;
    }
    bool empty(){
        return size == 0;
    }
};

int main(){

}