import java.util.*;
import java.math.*;

public class DengklekTryingToSleep {
	public int minDucks(int[] ducks) {
		Arrays.sort(ducks);
		Set<Integer> aux = new HashSet<Integer>();
		
		for(int i: ducks) aux.add(i);
		
		int ans = 0;
		
		for(int i = ducks[0] + 1; i <= ducks[ducks.length - 1] - 1; i++) {
			if(!aux.contains(i)) ans += 1;
		}
		
		return ans;
	}
}

// Powered by FileEdit
