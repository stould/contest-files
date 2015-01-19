import java.util.*;

public class NewYearResolution {
	public static void main(String[] args) {
		solve();
	}

	public static int T, N;
	
	public static int[] P = new int[22];
	public static int[] C = new int[22];
	public static int[] F = new int[22];

	public static void solve() {
		Scanner in = new Scanner(System.in);

		T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			P[21] = in.nextInt();
			C[21] = in.nextInt();
			F[21] = in.nextInt();

			N = in.nextInt();

			for (int i = 0; i < N; i++) {
				P[i] = in.nextInt();
				C[i] = in.nextInt();
				F[i] = in.nextInt();
			}

			String ans = "no";

			for (int i = 1; i < (1 << N); i++) {
				int[] curr = new int[3];
				
				for (int j = 0; j < N; j++) {
					if ((i & (1 << j)) > 0) {
						curr[0] += P[j];
						curr[1] += C[j];
						curr[2] += F[j];
					}
				}

				if (curr[0] == P[21] && curr[1] == C[21] && curr[2] == F[21]) {
					ans = "yes";
					break;
				}
			}
			System.out.println("Case #" + t + ": " + ans);
		}
	}
}
