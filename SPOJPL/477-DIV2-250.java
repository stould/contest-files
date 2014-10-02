import java.util.*;

public class VacationTime {
	public int bestSchedule(int N, int K, int[] working) {
		Set<Integer> set = new HashSet<Integer>();
		for(int i: working) { set.add(i); }
		int j = 0, ret = 1235421;
		int x = 0;
		for(int i = 1; i <= N; i++) {
			x = i;
			int c = 0;
			j = 0;
			while(x <= N && c < K) {
				if(set.contains(x)) {
					j++;
				}
				c++;
				x++;
			}
			if(c == K) {
				ret = Math.min(j, ret);			
			}
		}
		return ret;
	}
}
