import java.util.*;

public class GameOfLifeDivTwo {
	public String theSimulation(String in, int T) {
		int[] init = new int[in.length()];
		
		for(int i = 0; i < in.length(); i++) { init[i] = Integer.parseInt(""+in.charAt(i)); }
		int left = 0, atual = 0, right = 0, live = 0;

		for(int a = 0; a < T; a++) {
			String s = "";
			for(int i = 0; i < init.length; i++) {
					live = 0;
					left = i - 1 == -1 ? init[init.length - 1] : init[i - 1];
					atual = init[i];
					right = i + 1 == init.length? init[0] : init[i + 1];
					if(left == 1) {live++;}
					if(right == 1) {live++;}
					if(atual == 1) {live++;}
				if(live >= 2) {
					s += '1';
				} else {
					s += '0';
				}
			}
			for(int j = 0; j < s.length(); j++) { init[j] = s.charAt(j) - '0'; }
		}
		String tmp = "";
		
		for(int i: init) {
			tmp += i + "";
		}
		return tmp;
	}
}

// Powered by FileEdit