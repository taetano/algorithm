#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int n, k, visited[200004], prev[200004];
queue<int> q;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    
    visited[n] = 1;
    q.push(n);
    while(q.size()) {
        int cur = q.front(); q.pop();
        if (cur == k) {
            cout << visited[cur] - 1 << "\n";
            break;
        }
        
        for (int next : {cur + 1, cur - 1, cur * 2}) {
            if (next < 0 || next >= 200004 || visited[next]) continue;
            visited[next] = visited[cur] + 1;
            prev[next] = cur;
            q.push(next);
        }
    }
    for(int i = k; i != n; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    for (int each : v) cout << each << " ";
    
    return 0;
}