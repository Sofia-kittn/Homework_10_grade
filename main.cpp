#include <iostream>
#include "heap.h"
#include "rocks.h"

using namespace std;

int main(){
    int n;
    cin >> n;
    Heap h;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        h.insert(a);
    }
    cout << last_rock(h);
}