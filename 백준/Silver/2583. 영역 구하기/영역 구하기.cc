#include <bits/stdc++.h>
using namespace std;
const int M = 101;
const int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};
int m, n, k, sx, sy, ex, ey, total, a[M][M], visited[M][M];
vector<int> v;

int dfs(int y, int x, int cnt) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx] || !a[ny][nx]) continue;
        cnt = dfs(ny, nx, cnt + 1);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> k;
    fill(&a[0][0], &a[0][0] + 101 * 101, 1);
    while (k--) {
        cin >> sy >> sx >> ey >> ex;
        for (int i = sy; i < ey; i++) {
            for (int j = sx; j < ex; j++) {
                a[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] && !visited[i][j]) {
                int cnt = dfs(i, j, 1);
                v.push_back(cnt);
                total++;
            }
        }
    }
    
    cout << total << "\n";
    sort(v.begin(), v.end());
    for (auto each : v) {
        cout << each << " ";
    }
    return 0;
}