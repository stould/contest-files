import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class StreetWalking {
	public long minTime(int XX, int YY, int walkTime, int sneakTime) {		
		long X = (long) XX;
		long Y = (long) YY;
		
		if (X == Y && X == 0L) return 0L;
		
		if (X > Y) {
			long tmp = X;
			X = Y;
			Y = tmp;
		}
		
		//manhatthan
		if (2 * walkTime < sneakTime) {
			return walkTime * (X + Y);
		}	
		
		//diagonal + walk
		if (sneakTime > walkTime) {
			return X * sneakTime + (Y - X) * walkTime;
		}
		
		//parity for whole sneaks
		if ((X + Y) % 2L == 0L) {
			return Y * sneakTime;
		} else {		
			return (long) (Y - 1) * sneakTime + walkTime;
		}
	}
}

//Powered by [KawigiEdit] 2.0!