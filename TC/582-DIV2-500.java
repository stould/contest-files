import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class SpaceWarDiv2
{
	public int minimalFatigue(int[] mgs, int[] es, int[] ec)
	{
		int i, j, N = mgs.length, M = es.length, all = 0, T = 0;
		
		Arrays.sort(mgs);
		
		for (i = 0; i < M; i++) {
			for (j = i + 1; j < M; j++) {
				if (es[i] < es[j]) {
					int a = es[i], b = ec[i];
					es[i] = es[j]; ec[i] = ec[j];
					es[j] = a; ec[j] = b;
				}
			}
		}
		
		if (mgs[N-1] < es[0]) return -1;
		
		for (i = 0; i < M; i++) all += ec[i];
		
		for ( ; ; ) {
			T += 1;
			for (i = 0; i < N; i++) {
				for (j = 0; j < M; j++) {
					if (mgs[i] >= es[j] && ec[j] > 0) {
						ec[j] -= 1;
						all -= 1;
						if (all == 0) return T;
						break;
					}
				}
			}
		}
	}	
}

//Powered by [KawigiEdit] 2.0!
