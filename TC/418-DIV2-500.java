import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TwoLotteryGames {
	public double getHigherChanceGame(int n, int m, int k) {
		double un = 0.0, ex = 0.0;
		
		for (int i = 0; i < (1 << n); i++) {
			if (Integer.bitCount(i) == m) {
				for (int j = 0; j < (1 << n); j++) {
					if (Integer.bitCount(j) == m) {
						un += 1;
						
						int eq = 0;
						
						for (int x = 0; x < n; x++) {
							if ((i & (1 << x)) > 0 && (j & (1 << x)) > 0) {
								eq += 1;
							}
						}
						
						if (eq >= k) ex += 1;
					}
				}
			}
		}
		return ex / un;
	}
}

//Powered by [KawigiEdit] 2.0!
