import java.util.*;
import java.math.*;

public class InternetSecurity {
	public String[] determineWebsite(final String[] address, String[] keyword, String[] _dangerous, int threshold) {
		List<String> pre_ans = new ArrayList<String>(), dangerous = new ArrayList<String>();
		int i, j, k, N = address.length;
		
		for (i = 0; i < _dangerous.length; i++) dangerous.add(_dangerous[i]);
		
		boolean[] used = new boolean[N];
		
		while (true) {
			boolean changed = false;
			for (i = 0; i < N; i++) if (!used[i]) {
				int danger = 0;
				String[] tmp = keyword[i].split("\\s");
				for (j = 0; j < tmp.length; j++) {
					for (k = 0; k < dangerous.size(); k++) {
						if (tmp[j].equals(dangerous.get(k))) {
							danger += 1;
							break;
						}
					}
				}
				if (danger >= threshold) {
					pre_ans.add(address[i]);
					used[i] = changed = true;
					for (j = 0; j < tmp.length; j++) dangerous.add(tmp[j]);
				}
			}
			if (!changed) break;
		}		
		String[] ans = new String[pre_ans.size()];
		
		Collections.sort(pre_ans, new Comparator<String>() {
			public int compare(String s1, String s2) {
				if (id(address, s1, s2)) {
					return -1;
				} else {
					return 1;
				}
			}
		});
		
		for (i = 0; i < ans.length; i++) ans[i] = pre_ans.get(i);
		
		return ans;		
	}
	
	public boolean id(String[] address, String s1, String s2) {
		int i, N = address.length, ans_s1 = -1, ans_s2 = -1;
		
		for (i = 0; i < N; i++) {
			if (address[i].equals(s1)) ans_s1 = i;
			if (address[i].equals(s2)) ans_s2 = i;
		}
		
		return ans_s1 < ans_s2;
	}
}

// Powered by FileEdit
