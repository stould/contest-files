import java.util.*;
import java.math.*;

public class BinaryPolynomialDivTwo {
	public int countRoots(int[] a) {
		int ans = 0, rootA = 0, rootB = 0, x = 0;
		for(int i = 0; i < a.length; i++) {
			rootA += a[i] * Math.pow(1, x++);
		}
		x = 0;
		for(int i = 0; i < a.length; i++) {
			rootB += a[i] * Math.pow(0, x++);
		}
		rootA %= 2;
		rootB %= 2;
		if(rootA == 0) rootA = 1; else rootA = 0;
		if(rootB == 0) rootB = 1; else rootB = 0;		
		return rootA + rootB;

	}	
}


// Powered by FileEdit
