import java.util.*;

public class DNAString {
	public int minChanges(int max, String[] dna) {
		String all = "";
		for(int i = 0; i < dna.length; i++) all += dna[i];
		
		int mm = 10000;
		
		for(int i = 1; i <= max; i++) {
			int actual = 0;
			for(int j = 0; j < i; j++) {
				int k = j;
				int[] acc = new int[4];
				while(k < all.length()) {
					if(all.charAt(k) == 'A') acc[0] += 1;
					if(all.charAt(k) == 'C') acc[1] += 1;
					if(all.charAt(k) == 'G') acc[2] += 1;
					if(all.charAt(k) == 'T') acc[3] += 1;
					k += i;
				}
				int tmp = Math.max(acc[0], Math.max(acc[1], Math.max(acc[2], acc[3])));
				actual += (acc[0] + acc[1] + acc[2] + acc[3]) - tmp;
			}
			mm = Math.min(actual, mm);
		}
		return mm;
	}
}

// Powered by FileEdit