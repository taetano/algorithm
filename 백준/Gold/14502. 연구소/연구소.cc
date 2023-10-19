#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};
int a[10][10], visited[10][10], n, m, ret;
vector<pair<int,int>> virus_list, wall_list;

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] || a[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
}

int solve() {
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for (auto v : virus_list) {
        visited[v.first][v.second] = 1;
        dfs(v.first, v.second);
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) virus_list.push_back({i, j});
            else if (a[i][j] == 0) wall_list.push_back({i, j});
        }
    }
    
    for (int i = 0; i < wall_list.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                a[wall_list[i].first][wall_list[i].second] = 1;
                a[wall_list[j].first][wall_list[j].second] = 1;
                a[wall_list[k].first][wall_list[k].second] = 1;
                ret = max(ret, solve());
                a[wall_list[i].first][wall_list[i].second] = 0;
                a[wall_list[j].first][wall_list[j].second] = 0;
                a[wall_list[k].first][wall_list[k].second] = 0;
            }
        }
    }
    
    cout << ret;
    return 0;
}