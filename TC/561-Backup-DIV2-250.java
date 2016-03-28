import java.util.*;
import java.math.*;

public class FoxAndVacation {
    public int maxCities(int total, int[] d) {
        int ans = 0;
        Arrays.sort(d);
		
        for(int i = 0; i < d.length; i++) {
            if(d[i] <= total) {
                total -= d[i];
                ans += 1;
            }
        }
        return ans;		
    }
    public void debug(Object ... o) {
        System.out.println(Arrays.deepToString(o));
    }	
}

// Powered by FileEdit
