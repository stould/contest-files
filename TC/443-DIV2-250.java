import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class SoccerLeagues {
	public int[] points(String[] matches) {
		int N = matches.length;
		int[] ans = new int[N];
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (matches[i].charAt(j) == 'W') {
					ans[i] += 3;
				} else if (matches[i].charAt(j) == 'D') {
					ans[i] += 1;
					ans[j] += 1;
				} else if (matches[i].charAt(j) == 'L') {
					ans[j] += 3;
				}
			}
		}
		
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
