import java.util.*;
import java.math.*;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int N = in.nextInt();
		int BN = in.nextInt();

		int[] P = new int[50];
		int[] Q = new int[50];

		for (int i = 0; i < N; i++) {
			P[i] = in.nextInt();
		}

		int M = in.nextInt();
		int BM = in.nextInt();

		for (int i = 0; i < M; i++) {
			Q[i] = in.nextInt();
		}

		
		int pwA = 0;
		BigInteger valA = new BigInteger("0");
		
		for (int i = N - 1; i >= 0; i--) {
			valA = valA.add(new BigInteger("" + BN).pow(pwA++).multiply(new BigInteger("" + P[i])));
		}

		int pwB = 0;
		BigInteger valB = new BigInteger("0");
		
		for (int i = M - 1; i >= 0; i--) {
			valB = valB.add(new BigInteger("" + BM).pow(pwB++).multiply(new BigInteger("" + Q[i])));
		}

		if (valA.equals(valB)) {
			System.out.println("=");
		} else if (valA.compareTo(valB) < 0) {
			System.out.println("<");
		} else {
			System.out.println(">");
		}
		System.out.println(valA + " " + valB);
	}
}
