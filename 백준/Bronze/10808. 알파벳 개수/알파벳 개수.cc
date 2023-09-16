#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[26];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        char c = char(* (s.begin() + i));
        cnt[c - 'a']++;
    }
    for (int n : cnt) {
        cout << n << " ";
    }
    return 0;
}