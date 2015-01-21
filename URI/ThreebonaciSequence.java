import java.util.*;
import java.math.*;

public class ThreebonaciSequence {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		BigInteger[] P = new BigInteger[65];

		BigInteger A = new BigInteger("0");
		BigInteger B = new BigInteger("1");

		int cnt = 1;

		while (cnt <= 60) {
			BigInteger C = A.add(B);

			long digit = 0;
			boolean seen = false;

			String rep = C.toString();
			
			for (int i = 0; i < rep.length(); i++) {
				if (rep.charAt(i) == '3') {
					seen = true;
				}
				digit += rep.charAt(i) - '0';
			}

			if (seen || digit % 3 == 0) {
				P[cnt++] = C;
			}
			A = B;
			B = C;
		}
		
		while (in.hasNextInt()) {
			int N = in.nextInt();

			System.out.println(P[N].toString());
		}
	}
}
