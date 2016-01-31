import java.util.*;

public class NotTwo {
	public int maxStones(int width, int height) {	
		int num = 0; 
			
		for(int i = 0; i < height; i++) {
			for(int j = 0; j < width; j++) {
				if((i / 2) % 2 == 0 ^ (j / 2) % 2 != 0) {
					num++;
				}
			}
		}	
		return num;
	}	
	
	public boolean isValid(int x, int y, int H, int W) {
		return x >= 0 && y >= 0 && x < H && y < W;
	}
}

// Powered by FileEdit
