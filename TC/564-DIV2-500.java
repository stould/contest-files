import java.util.*;
import java.math.*;

public class AlternateColors {
	public String getColor(long r, long g, long b, long k) {
		String[] colors = {"RED", "GREEN", "BLUE"};

		long m = getMin(r, g, b);
		
		if(k <= 3*m) return colors[(int)((long)(k-1)%3L)];
		
		k -= 3L*m; r -= m; g -= m; b -= m;
				
		String[] colors2 = new String[2];
	
		int index = 0;
		
		if(r > 0L) colors2[index++] = "RED";
		if(g > 0L) colors2[index++] = "GREEN";
		if(b > 0L) colors2[index++] = "BLUE";
				
		m = getMin(r, g, b);
				
		if(k <= 2L*m) return colors2[(int)((long)(k-1)%(index))];
				
		k -= 2L*m; r -= m; g -= m; b -= m;
		
		if(r > 0L) return "RED";
		else if(g > 0L) return "GREEN";
		else return "BLUE";
		
	}
	public long getMin(long a, long b, long c) {
		long ans = Long.MAX_VALUE;
		if(a > 0L) ans = Math.min(ans, a);
		if(b > 0L) ans = Math.min(ans, b);
		if(c > 0L) ans = Math.min(ans, c);
		return ans;
	}	
}

// Powered by FileEdit
