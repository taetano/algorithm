import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n, m, mx = -987654321;
    static int[][] visited = new int[54][54];
    static char[][] a = new char[54][54];
    static List<Pair> lands = new ArrayList<>();
    static int[] dy = {-1,0,1,0}, dx = {0,1,0,-1};

    static void bfs(int y, int x) {
        visited[y][x] = 1;
        Deque<Pair> q = new LinkedList<>();
        q.addLast(new Pair(y, x));
        while (!q.isEmpty()) {
            Pair cur = q.removeFirst();
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + cur.first;
                int nx = dx[i] + cur.second;
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] != 0) continue;
                if (a[ny][nx] == 'W') continue;
                visited[ny][nx] = visited[cur.first][cur.second] + 1;
                q.addLast(new Pair(ny, nx));
                mx = Math.max(mx, visited[ny][nx]);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] sArr = br.readLine().split(" ");
        n = Integer.parseInt(sArr[0]);
        m = Integer.parseInt(sArr[1]);
        for (int i = 0; i < n; i++) {
            char[] chars = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                a[i][j] = chars[j];
                if (a[i][j] == 'L') lands.add(new Pair(i, j));
            }
        }

        for (Pair land : lands) {
            for (int[] v : visited) {
                Arrays.fill(v, 0);
            }
            bfs(land.first, land.second);
        }

        System.out.println(mx - 1);
    }

    static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}