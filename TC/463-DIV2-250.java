import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BunnyPuzzle {
	public int theCount(int[] bunnies) {
		int ans = 0;
		int N = bunnies.length;
		
		for (int i = 0; i < N; i++) {
			if (i - 1 >= 0) {
				int pos = 2 * bunnies[i - 1] - bunnies[i];
				
				if ((i - 2 < 0) || (bunnies[i - 2] < pos)) {
					ans += 1;
				}
			}
			if (i + 1 < N) {
				int pos = 2 * bunnies[i + 1] - bunnies[i];
				
				if ((i + 2 >= N) || (bunnies[i + 2] > pos)) {
					ans += 1;
				}		
			}
		}
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
