#include <bits/stdc++.h>
using namespace std;

int n, c, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;

int cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return mp_first[a.first] < mp_first[b.first];
    }
    
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    int i = 0;
    while (n--) {
        cin >> a[i];
        mp[a[i]]++;
        if (!mp_first[a[i]]) mp_first[a[i]] = i + 1;
        i++;
    }
    for (auto it : mp) {
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto p : v) {
        for (int i = 0; i < p.second; i++) {
            cout << p.first << " ";
        }
    }
    return 0;
}