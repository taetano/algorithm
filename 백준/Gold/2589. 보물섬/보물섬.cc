#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};
int visited[54][54], n, m, mx = -987654321;
vector<pair<int,int>> land_list;
char a[54][54];

void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int,int>> q;
	q.push({y, x});
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || a[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			mx = max(mx, visited[ny][nx]);
			q.push({ny, nx});
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
			if (a[i][j] == 'L') land_list.push_back({i, j});
        }
    }
    
    for (pair<int,int> land : land_list) {
    	memset(visited, 0, sizeof(visited));
    	bfs(land.first, land.second);
	}
	
	cout << mx - 1;
    return 0;
}