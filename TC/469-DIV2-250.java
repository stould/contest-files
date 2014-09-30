import java.util.*;

public class TheMoviesLevelOneDivTwo {
	public int find(int n, int m, int[] row, int[] seat) {
		boolean[][] maze = new boolean[n][m];
		
		for(int i = 0; i < row.length; i++) {
			maze[row[i] - 1][seat[i] - 1] = true;
		}
		int poss = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m - 1; j++) {
				if(!maze[i][j] && !maze[i][j + 1]) { poss++; }
			}
		}
		return poss;
	}
}

// Powered by FileEdit
