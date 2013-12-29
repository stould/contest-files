import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Autocomplete {
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

		String pref = input.readLine();

		int i;
		int N = Integer.parseInt(input.readLine());

		String ans = "%";

		for (i = 0; i < N; i++) {
			String curr = input.readLine();

			if (curr.startsWith(pref) && (ans.equals("%") || curr.compareTo(ans) < 0)) {
				ans = curr;
			}
		}

		System.out.println(ans == "%" ? pref : ans);
	}
}