import java.util.*;
import java.io.*;
import java.math.*;

public class PuzzleFromRed {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int D, K;

		for ( ; true; ) {
			D = in.nextInt();
			K = in.nextInt();

			if (D == 0 && K == 0) {
				break;
			}
			
			String S = "";
			
			for (int i = 0; i < K; i++) {
				S += ""+ D;
			}

			
			BigInteger bi = new BigInteger(S).pow(2);
			int ans = 0, L = bi.toString().length();
			String curr = bi.toString();

			for (int i = 0; i < L; i++) {
				ans += curr.charAt(i) - '0';
			}
			System.out.println(ans);
		}
	}
}
