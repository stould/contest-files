import java.io.*;
import java.math.*;

public class TheLastDigit {
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader((System.in)));

		int n = Integer.parseInt(input.readLine());

		for(int i = 0; i < n; i++) {
			String[] s = input.readLine().split("\\s");
			int base = Integer.parseInt(s[0]);
			int exp = Integer.parseInt(s[1]);

			String help = BigInteger.valueOf(base).pow(exp).toString();			
			System.out.println(help.charAt(help.length()-1));
		}
		System.exit(0);
	}
}
