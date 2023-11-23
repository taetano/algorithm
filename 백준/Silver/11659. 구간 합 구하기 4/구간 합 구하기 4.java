import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] sArr = br.readLine().split(" ");
        int n = Integer.parseInt(sArr[0]);
        int m = Integer.parseInt(sArr[1]);
        int[] psum = new int[n + 1];
        String[] arr = br.readLine().split(" ");
        int index = 1;
        for (String each : arr) {
            psum[index] = psum[index - 1] + Integer.parseInt(each);
            index++;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            String[] temp = br.readLine().split(" ");
            int start = Integer.parseInt(temp[0]);
            int end = Integer.parseInt(temp[1]);
            sb.append(psum[end] - psum[start - 1]).append(System.lineSeparator());
        }

        System.out.println(sb.toString());
    }

}