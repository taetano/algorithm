#include <bits/stdc++.h>
using namespace std;
int n, x, ret;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> x;
        if (x != 0) st.push(x);
        else if (!st.empty()) st.pop();
    }
    if (st.empty()) cout << 0;
    else {
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            ret += cur;
        }
        cout << ret;
    }
    return 0;
}