#include <bits/stdc++.h>
using namespace std;

const int MX = 1e4 + 4;
string op;
int n, x, pos, dat[MX];

void push(int x) {
    dat[pos++] = x;
}

int pop() {
    if (pos == 0)return -1;
    return dat[--pos];
}

int size() {
    return pos;
}

int empty() {
    return !size() ? 1 : 0; 
}

int top() {
    return empty() ? -1 : dat[pos - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x); 
        } else if (op == "pop") cout << pop() << '\n';
        else if (op == "size") cout << size() << '\n';
        else if (op == "empty") cout << empty() << '\n';
        else if (op == "top") cout << top() << '\n';
    }
    return 0;
}
