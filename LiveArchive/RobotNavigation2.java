import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.ParseException;
import java.util.Arrays;
import java.util.Scanner;
 
public class RobotNavigation2 {
 
	private void work() {
       Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(
                                       System.in), 1 << 16));
       String dirs = "NESW";
       int[] directionX = { -1, 0, 1, 0 };
       int[] directionY = { 0, 1, 0, -1 };
       int infinityish = Integer.MAX_VALUE / 16;
       int[] queue = new int[1 << 22];
       int queueStart, queueEnd;
 
       int tc = 1;
       while (true)
         {
           int m = scanner.nextInt();
           int n = scanner.nextInt();
           long mod = scanner.nextInt();
           if (mod == 0) {
			   break;
		   }
           System.out.printf("Case %d: %d ", tc++, mod);
           boolean[][] passable = new boolean[m + 2][n + 2];
		   
           for (int i = 1; i <= m; i++) {
               char[] line = scanner.next().toCharArray();
               for (int j = 1; j <= n; j++) {
                   if (line[j - 1] == '.') {
					   passable[i][j] = true;
				   }
			   }
		   }

           int startX = scanner.nextInt() + 1;
           int startY = scanner.nextInt() + 1;
           int targetX = scanner.nextInt() + 1;
           int targetY = scanner.nextInt() + 1;
           int startDir = dirs.indexOf(scanner.next().charAt(0));
 
           int[][][] dist = new int[4][m + 2][n + 2];
           int[][][] ans = new int[4][m + 2][n + 2];
 
           for (int i = 0; i < m + 2; i++) {
               for (int j = 0; j < 4; j++) {
                   Arrays.fill(dist[j][i], infinityish);
			   }
		   }

           dist[startDir][startX][startY] = 0;
           ans[startDir][startX][startY] = 1;
           queueStart = queueEnd = 0;
           queue[queueEnd++] = (startY << 12) | (startX << 2) | startDir;

           int res = -1;

           while (queueStart < queueEnd) {
               int y = queue[queueStart++];
               int dir = y & 3;
               y >>= 2;
               int x = y & 1023;
               y >>= 10;
			   
			   System.out.println((x - 1) + " " + (y - 1) + " " + dist[dir][x][y] + " " + ans[dir][x][y]);	   

               if (x == targetX && y == targetY) {
				   res = dist[dir][x][y];
                   break;
			   }
               int newX = x + directionX[dir];
               int newY = y + directionY[dir];
               if (passable[newX][newY] && dist[dir][newX][newY] > dist[dir][x][y] + 1) {
                   dist[dir][newX][newY] = dist[dir][x][y] + 1;
                   ans[dir][newX][newY] += ans[dir][x][y];
                   if (ans[dir][newX][newY] >= mod) {
					   ans[dir][newX][newY] -= mod;
				   }
                   queue[queueEnd++] = (newY << 12) | (newX << 2) | dir;
			   }
               else if (passable[newX][newY] && dist[dir][newX][newY] == dist[dir][x][y] + 1) {
                   ans[dir][newX][newY] += ans[dir][x][y];
                   if (ans[dir][newX][newY] >= mod) {
					   ans[dir][newX][newY] -= mod;
				   }
			   }
               int newDir = (dir + 3) & 3;
               if (dist[newDir][x][y] > dist[dir][x][y] + 1) {
                   dist[newDir][x][y] = dist[dir][x][y] + 1;
                   ans[newDir][x][y] += ans[dir][x][y];
                   if (ans[newDir][x][y] >= mod) {
					   ans[newDir][x][y] -= mod;
				   }
                   queue[queueEnd++] = (y << 12) | (x << 2) | newDir;
			   } else if (dist[newDir][x][y] == dist[dir][x][y] + 1) {
                   ans[newDir][x][y] += ans[dir][x][y];
                   if (ans[newDir][x][y] >= mod) {
					   ans[newDir][x][y] -= mod;
				   }
			   }
               newDir = (dir + 1) & 3;
               if (dist[newDir][x][y] > dist[dir][x][y] + 1) {
                   dist[newDir][x][y] = dist[dir][x][y] + 1;
                   ans[newDir][x][y] += ans[dir][x][y];
                   if (ans[newDir][x][y] >= mod) {
					   ans[newDir][x][y] -= mod;
				   }
                   queue[queueEnd++] = (y << 12) | (x << 2) | newDir;
			   } else if (dist[newDir][x][y] == dist[dir][x][y] + 1) {
                   ans[newDir][x][y] += ans[dir][x][y];
                   if (ans[newDir][x][y] >= mod) {
					   ans[newDir][x][y] -= mod;
				   }
			   }
		   }
           if (res < 0) {
               System.out.println(-1);
		   } else {
               int count = 0;
               for (int i = 0; i < 4; i++) {
                   if (dist[i][targetX][targetY] == res) {
                       count += ans[i][targetX][targetY];
                       if (count >= mod) {
						   count -= mod;
					   }
				   }
			   }
               System.out.println(count + " " + res);
		   }
         }
	}
	
	public static void main(String[] args) throws ParseException {
		new RobotNavigation2().work();
	}
}
