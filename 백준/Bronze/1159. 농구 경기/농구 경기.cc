#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
string s;
int N;
bool b;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while (N-- > 0) {
        cin >> s;
        char c = char(* (s.begin()));
        if (mp.find(c) == mp.end()) {
            mp.insert({c, 1});
            continue;
        }
        mp[c]++;
    }
    
    for (auto it: mp) {
        if (it.second >= 5) {
            cout << it.first;
            b = true;
        }
    }
    if (!b) {
        cout << "PREDAJA";
    }
    return 0;
}