import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class FallingPoints {
	public final double EPS = 1e-10;
	
	public double[] getHeights(int[] X, int RR) {
		int N = X.length;
		double[] Y = new double[N];
		
		double R = (double) RR;
		
		Y[0] = 0.0;
		
		for (int i = 1; i < N; i++) {
			int hor = Math.abs(X[i] - X[i - 1]);
			//R^2 = hor^2 + h^2
			//h = sqrt(R^2 - hor^2)
			
			double hypot = Math.sqrt(R * R - hor * hor);
			
			if (hor > R) {
				Y[i] = 0.0;
			} else {
				Y[i] = Y[i - 1] + hypot;
			}
		}
		
		return Y;
	}
	
	public boolean equals(double a, double b) {
		return Math.abs(a - b) <= EPS;
	}
}

//Powered by [KawigiEdit] 2.0
