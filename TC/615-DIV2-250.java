import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class AmebaDiv2 {
	public int simulate(int[] X, int A) {
		for (int i: X) {
			if (A == i) {
				A *= 2;
			}
		}
		return A;		
	}
}

//Powered by [KawigiEdit] 2.0!