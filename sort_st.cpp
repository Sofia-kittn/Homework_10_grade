#include "stack.h"
#include "sort_st.h"

void sort_st(Stack& s){
    Stack dop;

    while(!s.is_empty()){
        int cur = s.last_elem();
        s.pop_st();

        while(!dop.is_empty() && dop.last_elem() > cur){
            s.add(dop.last_elem());
            dop.pop_st();
        }
        dop.add(cur);
    }

    while(!dop.is_empty()){
        s.add(dop.last_elem());
        dop.pop_st();
    }
}