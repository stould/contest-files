import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(in.readLine());

        for ( ; T-- > 0; ) {
            String hay = in.readLine();
            String ned = in.readLine();

            int N = hay.length();
            int M = ned.length();

            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= M; j++) {
                    dp[i][j] = new BigInteger("-1");
                }
            }

            BigInteger ans = func(hay, ned, 0, 0);

            System.out.println(ans.toString());
        }
    }

    static BigInteger[][] dp = new BigInteger[10010][110];

    public static BigInteger func(String hay, String ned, int id_a, int id_b) {
        if (id_b == ned.length()) return new BigInteger("1");
        if (id_a == hay.length() || hay.length() - id_a < ned.length() - id_b) return new BigInteger("0");

        if (dp[id_a][id_b].compareTo(new BigInteger("-1")) != 0) {
            return dp[id_a][id_b];
        } else {
            dp[id_a][id_b] = new BigInteger("0");

            if (hay.charAt(id_a) == ned.charAt(id_b)) {
                dp[id_a][id_b] = dp[id_a][id_b].add(func(hay, ned, id_a + 1, id_b + 1));         
            }

            dp[id_a][id_b] = dp[id_a][id_b].add(func(hay, ned, id_a + 1, id_b));

            return dp[id_a][id_b];
        }
    }
}