import java.math.*;
import java.util.*;

public class TheChange {
    public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int T = Integer.parseInt(in.nextLine());
    
    StringTokenizer fs;

    for (int t = 1; t <= T; t++) {
        fs = new StringTokenizer(in.nextLine());

        BigInteger D = new BigInteger(fs.nextToken());
        BigInteger best = new BigInteger("0");

        int N = Integer.parseInt(fs.nextToken());
        
        D = D.multiply(new BigInteger("1000"));
        
        fs = new StringTokenizer(in.nextLine());        
        
        for (int i = 0; i < N; i++) {
        BigDecimal curr = new BigDecimal(fs.nextToken());

        curr = curr.multiply(new BigDecimal("1000"));

        BigInteger real = curr.toBigInteger();           
        
        if (real.compareTo(D) > 0) continue;
        
        BigInteger used = D.divide(real).multiply(real);
        
        BigInteger change = D.subtract(used);        
        
		
        best = best.max(change);
        }

        int ans = Integer.parseInt(best.toString());
        ans /= 10;
        
        int len = new String(ans / 100 + "." + (ans % 100)).length();
        
        int ii = ans / 100;
        int fr = ans % 100;
        
        System.out.println(ii + "." + (fr < 10 ? "0" : "") + fr);
    }
    }
}
