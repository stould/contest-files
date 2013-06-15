import java.util.*;
import java.math.*;

public class Trigo {
    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);

	int n = in.nextInt();

	for(int i = 0; i < n; i++) {
	    int v = in.nextInt();
	    System.out.println(func(v) + " kg");
	}
    }
    public static String func(int x) {
	BigInteger base = BigInteger.ZERO;

	for(int i = 0; i < x; i++) {
	    base = base.add(BigInteger.valueOf(2).pow(i));
	}
	base = base.divide(BigInteger.valueOf((int)(12.0*1000.0)));
	return base.toString();
    }
}