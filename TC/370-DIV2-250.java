import java.util.*;
import java.math.*;

public class Containers {
	public int wastedSpace(int[] containers, int[] packages) {
		int ans = 0;
		for(int i = 0; i < packages.length; i++) {
			Arrays.sort(containers);
			for(int j = 0; j < containers.length; j++) {
				if(packages[i] <= containers[j]) {
					containers[j] -= packages[i];
					break;
				}			
			}
		}
		for(int i: containers) ans += i;
		return ans;
	}	
}

// Powered by FileEdit
