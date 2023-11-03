#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> oper_str;
string s;
int n, ret = -987654321;

int oper(char op, int n1, int n2) {
    if (op == '+') return n1 + n2;
    if (op == '-') return n1 - n2;
    if (op == '*') return n1 * n2;
}

void go(int here, int sum) {
    if (here == num.size() - 1){
        ret = max(ret, sum);
        return;
    }
    
    go(here + 1, oper(oper_str[here], sum, num[here + 1]));
    if (here + 2 < num.size()) {
        int tmp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, oper(oper_str[here], sum, tmp));
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) num.push_back(s[i] - '0');
        else oper_str.push_back(s[i]);
    }
    go(0, num[0]);
    cout << ret;
}