import java.util.*;
import java.math.*;

public class BinaryFunction {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		in.nextLine();
		for ( ; T-- > 0; ) {
			String S = in.nextLine();
			System.out.println(new BigInteger(S).bitCount());
		}
	}
}
