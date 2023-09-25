#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
map<string, int> mp;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while (n-- > 0) {
        cin >> k;
        while (k-- > 0) {
            cin >> s >> s;
            if (mp.find(s) == mp.end()) {
                mp[s] = 2;
            } else {
                mp[s]++;
            }
        }
        int ret = 1;
        for (auto it : mp) {
            ret *= it.second;
        }
        cout << ret - 1 << "\n";
        mp.clear();
    }
    return 0;
}