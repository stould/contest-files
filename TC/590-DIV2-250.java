import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class FoxAndChess {
	public String ableToMove(String begin, String target) {
		String SB = "";
		String ST = "";
		
		for (char c : begin.toCharArray()) {
			if (c != '.') {
				SB += c;
			}
		}
	
		for (char c : target.toCharArray()) {
			if (c != '.') {
				ST += c;
			}
		}

		if (SB.equals(ST)) {
			int N = begin.length();
			
			List<Integer> L = new ArrayList<Integer>();
			List<Integer> R = new ArrayList<Integer>();
			
			for (int i = 0; i < N; i++) {
				if (begin.charAt(i) == 'L') {
					L.add(i);
				} else if (begin.charAt(i) == 'R') {
					R.add(i);
				}
			}

			int cntL = 0;
			int cntR = 0;			
			
			for (int i = 0; i < N; i++) {
				if (target.charAt(i) == 'R') {
					if (R.get(cntR) > i) {
						return "Impossible";
					}		
					cntR += 1;			
				}
				if (target.charAt(i) == 'L') {
					if (L.get(cntL) < i) {
						return "Impossible";
					}
					cntL += 1;
				}
			}
			
			return "Possible";
		} else {
			return "Impossible";
		}
	}
}

//Powered by [KawigiEdit] 2.0!
