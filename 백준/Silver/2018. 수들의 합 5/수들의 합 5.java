import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int startIdx = 1, endIdx = 1;
        int cnt = 1;
        int sum = 1;
        while (endIdx != n) {
            if (sum == n) {
                cnt++;
                endIdx++;
                sum += endIdx;
            } else if (sum > n) {
               sum -= startIdx;
                startIdx++;
            } else {
                endIdx++;
                sum += endIdx;
            }
        }
        System.out.print(cnt);
    }
}

