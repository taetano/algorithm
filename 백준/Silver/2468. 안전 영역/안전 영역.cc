#include <bits/stdc++.h>
using namespace std;
const int M = 101;
const int dy[] = {1,0,-1,0}, dx[] = {0,1,0,-1};
int n, cnt, ret, a[M][M], visited[M][M];

void createAdj() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void dfs(int y, int x, int d) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (visited[ny][nx] || a[ny][nx] <= d) continue;
        dfs(ny, nx, d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    createAdj();
    
    for (int d = 0; d < 101; d++) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > d && !visited[i][j]) {
                    cnt++;
                    dfs(i, j, d);
                }
            }
        }
        ret = max(ret, cnt);
    }
    
    cout << ret;
    return 0;
}