import java.util.*;
import java.math.*;

public class KeyDungeonDiv2 {
	public int countDoors(int[] doorR, int[] doorG, int[] keys) {
		int i, N = doorR.length, ans = 0;
		
		for (i = 0; i < N; i++) {
			int need_r = Math.max(0, doorR[i] - keys[0]);
			int need_g = Math.max(0, doorG[i] - keys[1]);
			
			if (need_r + need_g <= keys[2]) ans += 1;
		}
		
		return ans;		
	}
}

// Powered by FileEdit
