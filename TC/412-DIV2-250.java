import java.util.*;
import java.math.*;

public class TrueSpace {
	public long calculateSpace(int[] sizes, int clusterSize) {
		long ans = 0L;
		for(int i: sizes) {
			ans += (long) Math.ceil((double)i / (double)clusterSize) * clusterSize;
		}
		return ans;
	}	
}


// Powered by FileEdit
