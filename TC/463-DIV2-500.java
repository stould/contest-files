import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class RabbitNumbering {
	public final long MOD = 1000000007;
	
	public int theCount(int[] maxNumber) {
		Arrays.sort(maxNumber);
		
		long ans = 1L;
		int N = maxNumber.length;
		
		for (int i = 0; i < N; i++) {
			long avail = maxNumber[i] - i;

			if (avail <= 0) {
				ans = 0L;
				break;
			}
			ans = (ans * avail) % MOD;			
		}
		
		return (int) (ans % MOD);	
	}
}

//Powered by [KawigiEdit] 2.0!
