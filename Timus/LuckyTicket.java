import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	static BigInteger[][] dp = new BigInteger[105][1010];
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int N = in.nextInt();
		int S = in.nextInt();

		if (S % 2 != 0) {
			System.out.println(0);
		} else {
			for (int i = 0; i < 55; i++) {
				for (int j = 0; j < 1010; j++) {
					dp[i][j] = new BigInteger("-1");
				}
			}
			System.out.println(func(0, 0, N, S));
		}
	}
	public static BigInteger func(int pos, int sum, int N, int S) {
		if (pos == 2 * N) {
			return sum == 0 ? BigInteger.ONE : BigInteger.ZERO;
		} else if (sum > S || sum < 0 || pos > 2 * N) {
			return BigInteger.ZERO;
		} else 	if (pos == N && sum != S / 2) {
			return BigInteger.ZERO;
		} else {
			if (dp[pos][sum] == null || dp[pos][sum].equals(new BigInteger("-1"))) {
				dp[pos][sum] = BigInteger.ZERO;

				for (int i = 0; i <= 9; i++) {
					if (pos < N) {
						dp[pos][sum] = dp[pos][sum].add(func(pos + 1, sum + i, N, S));
					} else {
						dp[pos][sum] = dp[pos][sum].add(func(pos + 1, sum - i, N, S));
					}
				}
			}

			return dp[pos][sum];
		}
	}
}
