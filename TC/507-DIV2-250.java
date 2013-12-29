public class CubeAnts {
	public int getMinimumSteps(int[] pos) {
		int n = pos.length;
		int ret = 0;
						
		for(int i = 0; i < n; i++) {
			if(pos[i] == 6) return 3;
			else if(pos[i] == 5 || pos[i] == 2 || pos[i] == 7) {
				ret = Math.max(2, ret);
			} else if(pos[i] == 1 || pos[i] == 3 || pos[i] == 4) {
				ret = Math.max(1, ret);
			}
		}
		return ret;
	}
}