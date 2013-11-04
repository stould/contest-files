import java.util.*;
import java.math.*;

public class FoxAndKgram {
	public int maxK(int[] len) {
		Arrays.sort(len);
		int max = 0;
		int num = 0;
		
		for(int tmp = 1; tmp <= 200; tmp++) {
			int K = tmp;
			boolean[] used = new boolean[len.length];

			int form = 0;
			
			for(int i = 0; i < len.length; i++) {
				if(len[i] == K) {
					form += 1;
					used[i] = true;
				}
			}
			
			for(int i = 0; i < len.length; i++) {
				for(int j = i + 1; j < len.length; j++) {
					if(!used[i] && !used[j] && len[i] + len[j] == K - 1) {
						form += 1;
						used[i] = used[j] = true;
					}				
				}				
			}			
			if(form >= K) {
				max = Math.max(max, K);			
			}
		}
		return max;
	}	
}

// Powered by FileEdit