import java.util.*;
import java.io.*;

import static java.lang.Integer.*;

public class EugenyAndPlaylist {
	public static final int MAXN = 100005;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] line1 = in.readLine().split(" ");

		int[] beg = new int[MAXN];
		int[] end = new int[MAXN];
	   
		int N = parseInt(line1[0]);
		int M = parseInt(line1[1]);

		for (int i = 0; i < N; i++) {
			String[] line2 = in.readLine().split(" ");

			int A = parseInt(line2[0]);
			int B = parseInt(line2[1]);

			if (i == 0) {
				beg[i] = 1;
				end[i] = A * B;
			} else {
				beg[i] = end[i - 1] + 1;
				end[i] = beg[i] + A * B - 1;
			}
		}

		String[] line3 = in.readLine().split(" ");

		for (int i = 0; i < M; i++) {
			int curr = parseInt(line3[i]);

			int l = 0, h = N - 1, m;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				if (curr >= beg[m] && curr <= end[m]) {
					System.out.println(m + 1);
					break;
				} else if (curr < beg[m]) {
					h = m - 1;
				} else {
					l = m + 1;
				}
			}
		}

		in.close();
	}
}