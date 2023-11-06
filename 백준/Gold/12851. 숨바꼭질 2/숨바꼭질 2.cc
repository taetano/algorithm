#include <bits/stdc++.h>
using namespace std;

int n, k, visited[100004], cnt[100004];
queue<int> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
  	if (n == k) {
  		puts("0"); puts("1");
  		return 0;
	  }
  	
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    while(q.size()) {
        int cur = q.front(); q.pop();
        
        for (int next : {cur + 1, cur - 1, cur * 2}) {
            if (next < 0 || next > 100000) continue;
            
            if (!visited[next]) {
            	visited[next] = visited[cur] + 1;
            	cnt[next] += cnt[cur];
            	q.push(next);
			} else if (visited[next] == visited[cur] + 1) {
				cnt[next] += cnt[cur];
			}
        }
    }
    
    cout << visited[k] - 1 << "\n";
    cout << cnt[k];
    
    return 0;
}