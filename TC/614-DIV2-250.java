import java.util.*;

public class MicroStrings {
	public String makeMicroString(int A, int D) {
		String ans = "";
		
		for (int i = 0; A - i * D >= 0; i++) {
			ans += "" + (A - i * D);
		}
	
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
