#include <bits/stdc++.h>
using namespace std;

string s;
list<char> L;
int n;
char cmd, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s;
    for (char c : s) L.push_back(c);
    auto cursor = L.end();
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == 'P') {
            cin >> v;
            L.insert(cursor, v);
        } else if (cmd == 'L') {
            if (cursor != L.begin()) cursor--;
        } else if (cmd == 'D') {
            if (cursor != L.end()) cursor++;
        } else if (cmd == 'B') {
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for (char c : L) cout << c;
    return 0;
}