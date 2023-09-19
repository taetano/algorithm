#include <bits/stdc++.h>
using namespace std;
int n, pos;
string p, s, pre, suf;

int main() {
    cin >> n >> p;
    int pos = p.find("*");
    pre = p.substr(0, pos);
    suf = p.substr(pos + 1);
    while(n-- > 0) {
        cin >> s;
        if (s.size() < pre.size() + suf.size()) {
            cout << "NE" << "\n";
            continue;
        }
        
        if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA" << "\n";
        else cout << "NE" << "\n";
    }
    return 0;
}