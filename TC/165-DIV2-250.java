import java.util.*;

public class BritishCoins {
	public int[] coins(int pence) {
		int[] ans = new int[3];
		ans[0] = (pence / 12 / 20);
		ans[1] = (pence - (ans[0] * 20 * 12)) / 12;
		ans[2] = (pence - (ans[0] * 20 * 12)) - ans[1] * 12;
		return ans;		
	}	
}


// Powered by FileEdit
