#include <bits/stdc++.h>
using namespace std;

int n, k, visited[100004];
queue<int> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
  
    q.push(n);
    visited[n] = 1;
    while(q.size()) {
        int cur = q.front(); q.pop();
        if (cur == k) {
            cout << visited[cur] - 1;
            break;
        }
        
        for (int next : {cur + 1, cur - 1, cur * 2}) {
            if (next < 0 || next > 100000 || visited[next]) continue;
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
    
    return 0;
}