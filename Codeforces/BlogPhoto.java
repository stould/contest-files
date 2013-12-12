import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class BlogPhoto {
	public static final double EPS = 1e-7;

	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

		String[] sp = input.readLine().split(" ");

		int H = Integer.parseInt(sp[0]);
		int W = Integer.parseInt(sp[1]);

		int base;
		long ans = 0L;

		int ans_H = 0;
		int ans_W = 0;

		base = 0;
		for (; pow(2.0, base) <= W; base++) {
			long cw = (long) pow(2.0, base);			
			long ch = Math.min(H, (long) cw * 5 / 4);

			long ratio = cw * ch;

			if (ch * 4 > cw * 5) continue;

			if (ratio > ans || (ratio == ans && ch > ans_H)) {
				ans_H = (int) ch;
				ans_W = (int) cw;
				ans = ratio;
			}
		}

		base = 0;
		for (; pow(2.0, base) <= H; base++) {
			long ch = (long) pow(2.0, base);			
			long cw = Math.min(W, (long) ch * 5 / 4);

			long ratio = cw * ch;

			if (ch * 4 > cw * 5) continue;

			if (ratio > ans || (ratio == ans && ch > ans_H)) {
				ans_H = (int) ch;
				ans_W = (int) cw;
				ans = ratio;
			}
		}


		System.out.printf("%d %d\n", ans_H, ans_W);
	}
}