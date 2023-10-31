#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};
int n, m, sy, sx, y, x, ret;
int person_check[1004][1004], fire_check[1004][1004];
char a[1004][1004];

bool in(int a, int b) {
    return a >= 0 && b >= 0 && a < n&& b < m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);
    cin >> n >> m;
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'F') {
                fire_check[i][j] = 1; q.push({i, j});
            } else if (a[i][j] == 'J') {
                sy = i; sx = j;
            }
        }
    }
    
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (!in(ny, nx)) continue;
            if (fire_check[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire_check[ny][nx] = fire_check[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    person_check[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        if (y == 0 || x == 0 || y == n - 1 || x == m - 1) {
            ret = person_check[y][x];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (!in(ny, nx)) continue;
            if (person_check[ny][nx] || a[ny][nx] == '#') continue;
            if (fire_check[ny][nx] <= person_check[y][x] + 1) continue;
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    if (ret) cout << ret;
    else cout << "IMPOSSIBLE";
    
    return 0;
}