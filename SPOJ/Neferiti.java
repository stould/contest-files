import java.math.*;
import java.io.*;

public class Neferiti {
	public static BigInteger[][] dp = new BigInteger[101][1 << 12];
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		//int T = parseInt(in.readLine());

		System.out.print("string ans[101][7] = {");
		
		for (int N = 1; N <= 100; N++) {
			System.out.print("{");
			for (int K = 1; K <= 6; K++) {				
				for (int i = 0; i <= N; i++) {
					for (int j = 0; j < (1 << (2 * K)); j++) {
						dp[i][j] = new BigInteger("-1");
					}
				}
				
				BigInteger ans = func(0, 0, N, K);
				//out.write(ans.toString(), 0, ans.toString().length());
				//out.newLine();
				System.out.print("\"" + ans + "\"");
				if (K != 6) {
					System.out.print(", ");
				}
			}
			System.out.print("}");
			if (N != 100) {
				System.out.print(", ");
			}
		}
		
		System.out.print("};");


		in.close();
		out.close();
	}

	public static int parseInt(String s) {
		int ans = 0;

		for (int i = 0; i < s.length(); i++) {
			ans = ans * 10 + (s.charAt(i) - '0');
		}
		
		return ans;
	}
	
	public static BigInteger func(int pos, int mask, int N, int K) {
		if (pos == N) {
			return BigInteger.ONE;
		} else {
			if (dp[pos][mask].equals(new BigInteger("-1"))) {
				dp[pos][mask] = BigInteger.ZERO;

				for (int np = pos - K, ms = 0; np <= pos + K; np++, ms++) {
					if (np < 0 || np >= N) {
						continue;
					}
					if ((mask & (1 << ms)) == 0) {
						dp[pos][mask] = dp[pos][mask].add(func(pos + 1, (mask | (1 << ms)) >> 1, N, K));
					}
				}
			}

			return dp[pos][mask];
		}
	}

}
