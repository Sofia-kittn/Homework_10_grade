#include "heap.h"
#include "rocks.h"

int last_rock(Heap& h){
    int n = h.what_size();

    while(n > 1){
        int x = h.del_m(), y = h.del_m();
        n -= 2;
        if(x != y){
            h.insert(x - y);
            n++;
        }
    }

    if(n == 0) return 0;
    return h.get_m();
}