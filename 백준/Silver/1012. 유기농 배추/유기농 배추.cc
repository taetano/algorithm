#include <bits/stdc++.h>
using namespace std;
const int M = 50;
const int dy[] = {1,0,-1,0};
const int dx[] = {0,1,0,-1};
int t, n, m, k, x, y, a[M][M], visited[M][M];

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (visited[ny][nx] || !a[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        fill(&a[0][0], &a[0][0] + 50 * 50, 0);
        fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
        int ret = 0;
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] && !visited[i][j]) {
                    ret++;
                    dfs(i, j);
                }
            }
        }
        cout << ret << "\n";
    }
    return 0;
}