#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int dp[10001], visited[10001];
int n, m, a, b, mx;

int dfs(int here) {
    visited[here] = 1;
    int ret = 1;
    for (int there : v[here]) {
        if (visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        fill(visited, visited + 10001, 0);
        dp[i] = dfs(i);
        mx = max(mx, dp[i]);
    }
    for (int i = 1; i <= n; i++) if (dp[i] == mx) cout << i << " ";
    
    return 0;
}