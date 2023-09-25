#include <bits/stdc++.h>
using namespace std;
int n, ret;
string s;

int main() {
    cin.tie(NULL);
    cin >> n;
    while (n-- > 0) {
        cin >> s;
        deque<char> dq;
        for (char c : s) {
            if (!dq.size() || dq.back() != c) dq.push_back(c);
            else dq.pop_back();
        }
        if (!!dq.size()) {
            continue;
        }
        ret++;
    }
    cout << ret;
    return 0;
}