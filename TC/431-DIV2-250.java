import java.util.*;
import java.math.*;

public class MegaCoolNumbersEasy {
	public int count(int N) {
		int i, ans = 0;
		
		for (i = 1; i <= N; i++) {
			if (func(i)) ans += 1;
		}
		
		return ans;
	}
	
	public boolean func(int x) {
		int[] dp = new int[5];
		int i, len = 0;
		
		while (x > 0) {
			dp[len++] = x % 10;
			x /= 10;
		}
		
		if (len == 1) return true;
		
		int ratio = dp[0] - dp[1];
		
		for (i = 0; i < len - 1; i++) {
			if (dp[i] - dp[i + 1] != ratio) return false;
		}
		
		return true;
	}
}

// Powered by FileEdit
