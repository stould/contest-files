import java.util.*;
import java.io.*;

public class DateDiference {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		int T = parse(in.readLine());

		for ( ; T-- > 0; ) {
			String[] sf = in.readLine().split(" ");
			String[] st = sf[0].split("-");
			String[] ed = sf[1].split("-");
			
			Calendar start = Calendar.getInstance();
			Calendar end = Calendar.getInstance();

			start.set(parse(st[0]), parse(st[1]), parse(st[2]));
			end.set(parse(ed[0]), parse(ed[1]), parse(ed[2]));

			Date startDate = start.getTime();
			Date endDate = end.getTime();

			long startTime = startDate.getTime();
			long endTime = endDate.getTime();
			long diffTime = endTime - startTime;
			long diffDays = diffTime / (1000 * 60 * 60 * 24);

			System.out.println(Math.abs(diffDays));
		}
	}
	public static int parse(String S) {
		int ans = 0;

		for (int i = 0; i < S.length(); i++) {
			ans = ans * 10 + (S.charAt(i) - '0');
		}
		return ans;
	}
}
