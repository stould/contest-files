import java.util.*;
import java.math.*;

public class SurroundingGameEasy {
	public int[] dx = {1, 0, -1, 0};
	public int[] dy = {0, 1, 0, -1};
	public int score(String[] cost, String[] benefit, String[] stone) {
		int b = 0, s = 0, N = stone.length, M = stone[0].length();
	
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(stone[i].charAt(j) == 'o') {
					s += cost[i].charAt(j) - '0';
					b += benefit[i].charAt(j) - '0';
				} else {
					int check = 0, ok = 0;
					for(int k = 0; k < 4; k++) {
						int ii = i + dx[k];
						int jj = j + dy[k];
						if(ii >= 0 && jj >= 0 && ii < N && jj < M) {
							check += 1;
							if(stone[ii].charAt(jj) == 'o') {
								ok += 1;
							}	
						}
					}
					if(check == ok) b += benefit[i].charAt(j) - '0';
				}
			}	
		}
		return b - s;
	}	
}


// Powered by FileEdit
