import java.util.*;
import java.math.*;

public class DengklekMakingChains {
	public int maxBeauty(String[] chains) {
		int ans = 0, if_not_possible_ans = 0;
		
		for(int i = 0; i < chains.length; i++) {
			int tmp = 0;
			for(int j = 0; j < 3; j++) if(chains[i].charAt(j) != '.') {
				tmp += chains[i].charAt(j) - '0';
				if_not_possible_ans = Math.max(chains[i].charAt(j) - '0', if_not_possible_ans);
			}
			if(!chains[i].contains(".")) {
				ans += tmp;
			}
		}
		System.out.println(if_not_possible_ans);
		return Math.max(if_not_possible_ans, ans + Math.max(preffixBeforeSuffix(chains), suffixBeforePrefix(chains)));
	}
	public int preffixBeforeSuffix(String[] chains) {
		int maxPreffix = 0, maxSuffix = 0, index = -1;
		for(int i = 0; i < chains.length; i++) if(chains[i].contains(".")) {	
			int prev_preffix = 0;
			for(int j = 2; j >= 0 && chains[i].charAt(j) != '.'; j--) prev_preffix += chains[i].charAt(j) - '0';
			if(prev_preffix > maxPreffix) {
				maxPreffix = prev_preffix;
				index = i;
			}
		}
		for(int i = 0; i < chains.length; i++) if(chains[i].contains(".")) {	
			int prev_suffix = 0;
			for(int j = 0; j <  3 && chains[i].charAt(j) != '.'; j++) prev_suffix += chains[i].charAt(j) - '0';
			if(prev_suffix > maxSuffix && i != index) {
				maxSuffix = prev_suffix;	
			}
		}
		return maxPreffix + maxSuffix;
	}
	public int suffixBeforePrefix(String[] chains) {
		int maxPreffix = 0, maxSuffix = 0, index = -1;
		for(int i = 0; i < chains.length; i++) if(chains[i].contains(".")) {	
			int prev_suffix = 0;
			for(int j = 0; j <  3 && chains[i].charAt(j) != '.'; j++) prev_suffix += chains[i].charAt(j) - '0';
			if(prev_suffix > maxSuffix) {
				maxSuffix = prev_suffix;	
				index = i;
			}
		}
		for(int i = 0; i < chains.length; i++) if(chains[i].contains(".")) {	
			int prev_preffix = 0;
			for(int j = 2; j >= 0 && chains[i].charAt(j) != '.'; j--) prev_preffix += chains[i].charAt(j) - '0';
			if(prev_preffix > maxPreffix && i != index) {
				maxPreffix = prev_preffix;
			}
		}
		return maxPreffix + maxSuffix;
	}
}

// Powered by FileEdit
