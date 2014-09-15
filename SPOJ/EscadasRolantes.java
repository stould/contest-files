import java.io.*;
import java.util.*;
import java.math.*;

public class EscadasRolantes {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		BigInteger S = new BigInteger(in.readLine());
		BigInteger D = new BigInteger(in.readLine());
		
		int r = 0;

		while (S.compareTo(BigInteger.ZERO) > 0) {
			int len = S.toString().length();
			int parity = (S.toString().charAt(len - 1) - '0') % 2;

			if (parity == 0) {
				r = 1 - r;
			}
			S = S.divide(D);
		}

		if (r == 0) {
			System.out.println("sobe desce");
		} else {
			System.out.println("desce sobe");
		}
	}
}
