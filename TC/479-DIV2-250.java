import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class TheAirTripDivTwo {
	public int find(int[] flights, int fuel) {
		int i;
		int N = flights.length;
		
		for (i = 0; i < N; i++) {
			fuel -= flights[i];
			if (fuel < 0) break;
		}
		
		return i;
	}
}

//Powered by [KawigiEdit] 2.0!
