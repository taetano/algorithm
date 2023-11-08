#include <bits/stdc++.h>
using namespace std;

const int mx_n = 1e5 * 5;
int visited[2][mx_n + 4], n, k, turn = 1;
bool flag;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if(n == k) {
        cout << 0 << "\n";
        return 0;
    }
    queue<int> q;
    q.push(n);
    visited[0][n] = 1;
    while(q.size()) {
        k += turn;
        if (k > mx_n) break;
        if (visited[turn % 2][k]) {
            flag = 1;
            break;
        }
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int cur = q.front(); q.pop();
            for (int next : {cur + 1, cur - 1, cur * 2}) {
                if (next < 0 || next > mx_n || visited[turn % 2][next]) continue;
                if (next == k) {
                    flag = 1;
                    break;
                }
                visited[turn % 2][next] = visited[(turn + 1) % 2][cur] + 1;
                q.push(next);
            }
            if (flag) break;
        }
        if (flag) break;
        turn++;
    }
    if (flag) cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;
}