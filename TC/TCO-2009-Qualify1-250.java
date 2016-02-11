import java.util.Arrays;

public class SortingWithPermutation {
	public int[] getPermutation(int[] a) {
		int N = a.length, pivot = 0;
		int[] ans = new int[N];
		int[] hp = new int[N];
		
		for(int i = 0; i < N; i++) hp[i] = a[i];

		Arrays.sort(a);
		
		for(int i = 0; i < N; i++) {
			int index = -1;
			for(int j = 0; j < N; j++) {
				if(hp[i] == a[j]) {
					index = j;
					break;
				}
			}	
			ans[i] = index;
			a[index] = -1;
		}	
	
		return ans;
	}
}


// Powered by FileEdit
