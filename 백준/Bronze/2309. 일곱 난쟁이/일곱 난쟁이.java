import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int[] a = new int[9];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 9; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(a);
        permutation(0, 9, 7, a);
    }

    static void permutation(int depth, int n, int r, int[] a) {
        if (depth == r) {
            int sum = 0;
            for (int i = 0; i < 7; i++) {
                sum += a[i];
            }
            if (sum == 100) {
               Arrays.sort(a, 0, 7);
               for (int i = 0; i < 7; i++) {
                   System.out.println(a[i]);
               }
               System.exit(0);
            }
        }

        for (int i = depth; i < n; i++) {
            swap(depth, i, a);
            permutation(depth + 1, n, r, a);
            swap(depth, i, a);
        }
    }

    static void swap(int idx1, int idx2, int[] a) {
        int tmp = a[idx1];
        a[idx1] = a[idx2];
        a[idx2] = tmp;
    }
}