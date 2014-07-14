import java.math.*;
import java.util.*;
import java.io.*;

public class UncleJack {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int A, B;

		for ( ; true; ) {
			A = in.nextInt();
			B = in.nextInt();

			if (A + B == 0) break;

			BigInteger b = new BigInteger(""+A).pow(B);
			System.out.print(b.toString());
		}
	}
}
