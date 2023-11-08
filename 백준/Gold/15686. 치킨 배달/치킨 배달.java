import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int n, m, ans = 987654321;
    static List<List<Integer>> chickenCombi = new ArrayList<>();
    static List<Pair> homes = new ArrayList<>();
    static List<Pair> chickens = new ArrayList<>();
    static int[][] a = new int[54][54];

    static void combi(int depth, List<Integer> list) {
        if (list.size() == m) {
            chickenCombi.add(new ArrayList<>(list));
        }

        for (int i = depth; i < chickens.size(); i++) {
            list.add(i);
            combi(i + 1, list);
            list.remove(list.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] split = br.readLine().split(" ");
        n = Integer.parseInt(split[0]);
        m = Integer.parseInt(split[1]);
        for (int i = 0; i < n; i++) {
            String[] s = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                a[i][j] = Integer.parseInt(s[j]);
                if (a[i][j] == 1) homes.add(new Pair(i, j));
                else if (a[i][j] == 2) chickens.add(new Pair(i, j));
            }
        }

        List<Integer> list = new ArrayList<>();
        combi(0, list);
        for (List<Integer> com : chickenCombi) {
            int ret = 0;
            for (Pair home : homes) {
                int min = 987654321;
                for (int ch : com) {
                    int dist = Math.abs(home.first - chickens.get(ch).first) + Math.abs(home.second - chickens.get(ch).second);
                    min = Math.min(min, dist);
                }
                ret += min;
            }
            ans = Math.min(ret, ans);
        }

        System.out.println(ans);
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