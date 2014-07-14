import java.util.*;
import java.math.*;

public class caso_arestas {
	public static void main(String[] args) {
		BigInteger[] b = new BigInteger[10001];

		b[0] = new BigInteger("2");
		b[1] = new BigInteger("1");

		for (int i = 2; i <= 10000; i++) {
			b[i] = b[i - 1].add(b[i - 2]);
		}
		
		Scanner input = new Scanner(System.in);

		while (input.hasNext()) {
			int a = input.nextInt();

			System.out.println(b[a].toString());
		}
	}
}
