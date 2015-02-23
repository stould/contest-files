import java.io.BufferedReader;
import java.io.InputStreamReader;

public class FoxAndCross {
	public static final int[] dx = { 0, -1, 1, 0, 0 };
	public static final int[] dy = { 0, 0, 0, -1, 1 };

	public static void main(String[] args) throws Throwable {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(in.readLine());

		String[] S = new String[N];
		boolean[][] used = new boolean[N][N];

		for (int i = 0; i < N; i++) {
			S[i] = in.readLine();
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!used[i][j] && S[i].charAt(j) == '#') {
					int cnt = 0;

					for (int k = 0; k < 5; k++) {
						int di = i + dx[k];
						int dj = j + dy[k];

						if (di >= 0 && dj >= 0 && di < N && dj < N
								&& !used[di][dj] && S[di].charAt(dj) == '#') {
							cnt++;
						}
					}

					if (cnt == 5) {		
						
						for (int k = 0; k < 5; k++) {
							int di = i + dx[k];
							int dj = j + dy[k];

							if (di >= 0 && dj >= 0 && di < N && dj < N
									&& !used[di][dj] && S[di].charAt(dj) == '#') {
								used[di][dj] = true;
							}
						}
					}
				}
			}
		}
		
		boolean ok = true;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!used[i][j] && S[i].charAt(j) == '#') {
					ok = false;
				}
			}
		}
		
		if (ok) {
			System.out.println("YES");
		} else {
			System.out.println("NO");		
		}
		
		in.close();		
	} 
}
