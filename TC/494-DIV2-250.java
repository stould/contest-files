import java.util.*;

public class InterestingParty {
	public int bestInvitation(String[] first, String[] second) {
		int max = 0, N = first.length;
		
		for(int i = 0; i < N; i++) {
			int nowA = 1, nowB = 1;
			for(int j = 0; j < N; j++) if(i != j) {
				if(first[i].equals(first[j]) || first[i].equals(second[j])) {
					nowA += 1;
				}
			}
			for(int j = 0; j < N; j++) if(i != j) {
				if(second[i].equals(first[j]) || second[i].equals(second[j])) {
					nowB += 1;
				}
			}
			max = Math.max(max, Math.max(nowA, nowB));
		}		
		return max;
	}	
}


// Powered by FileEdit