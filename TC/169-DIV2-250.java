import java.util.*;

public class Swimmers {
	public int[] getSwimTimes(int[] distances, int[] speeds, int current) {
		int N = speeds.length;
		int[] ans = new int[N];
		
		for(int i = 0; i < N; i++) {
			if(speeds[i] <= current && distances[i] != 0) {
				ans[i] = -1;
			} else {
				double go = speeds[i] + current;
				double ww = speeds[i] - current;				
				double help = (double) ((double) (distances[i] / go) + (double) (distances[i] / ww));
				ans[i] = (int) Math.floor(help);
			}
		}		
		return ans;
	}
}

// Powered by FileEdit
