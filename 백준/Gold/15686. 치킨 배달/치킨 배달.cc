#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 987654321, a[54][54];
vector<pair<int,int>> home_list, chiken_list;
vector<vector<int>> chiken_combi_list;

void combi(int start, vector<int> v) {
    if (v.size() == m) {
        chiken_combi_list.push_back(v);
        return;
    }
    
    for (int i = start; i < chiken_list.size(); i++) {
        v.push_back(i);
        combi(i + 1, v);
        v.pop_back();
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) home_list.push_back({i, j});
            else if (a[i][j] == 2) chiken_list.push_back({i, j});
        }
    }
    vector<int> v;
    combi(0, v);
    for (vector<int> chiken_combi : chiken_combi_list) {
        int ret = 0;
        for (pair<int,int> home: home_list) {
            int _min = 987654321;
            for (int ch : chiken_combi) {
                int _dist = abs(home.first - chiken_list[ch].first) + abs(home.second - chiken_list[ch].second);
                _min = min(_min, _dist);
            }
            ret += _min;
        }
        ans = min(ans, ret);
    }
    
    cout << ans;
    return 0;
}