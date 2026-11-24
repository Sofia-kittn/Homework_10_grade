#include "stack.h"
#include "sort_st.h"
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    Stack s;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.add(a);
    }
    sort_st(s);
}