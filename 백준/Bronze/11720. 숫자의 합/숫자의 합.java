import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(br.readLine());
        String b = br.readLine();
        int ret = 0;
        for (char c : b.toCharArray()) {
            ret += (c - '0');
        }
        System.out.println(ret);
    }
    
}