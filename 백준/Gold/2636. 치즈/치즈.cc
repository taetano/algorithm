#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};
int a[104][104], visited[104][104];
int n, m, cnt, cnt2;
vector<pair<int,int>> V;

void go(int y, int x) {
    visited[y][x] = 1;
    if (a[y][x] == 1) {
        V.push_back({y, x});
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;
            go(ny, nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    while (true) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        V.clear();
        go(0, 0);
        cnt2 = V.size(); // 지워지기 전 치즈 수
        for (auto c : V) {
            a[c.first][c.second] = 0;
        }
        
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0) flag = 1;
            }
        }
        cnt++;
        
        if (!flag) break;
    }
    
    cout << cnt << "\n" << cnt2 << "\n";
    
    return 0;
}