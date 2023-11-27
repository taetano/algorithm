import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        int m = Integer.parseInt(br.readLine());
        int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(a);
        int cnt = 0;
        int startIdx = 0, endIdx = a.length - 1;
        while (startIdx < endIdx) {
            int tmp = a[startIdx] + a[endIdx];
            if (tmp == m) {
                startIdx++;
                endIdx--;
                cnt++;
            } else if (tmp < m) {
                startIdx++;
            } else {
                endIdx--;
            }
        }
        System.out.println(cnt);
    }
}
