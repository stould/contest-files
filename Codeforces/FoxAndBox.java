import java.util.Arrays;
import java.util.Scanner;

public class FoxAndBox {
	public static void main(String[] args) throws Throwable {		
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		
		int[] B = new int[N];
		boolean[] used = new boolean[N];
		
		for (int i = 0; i < N; i++) {
			B[i] = in.nextInt();
		}
		
		Arrays.sort(B);
		
		int ans = 0;
		
		for (int x = 0; x < N; x++) {
			if (!used[x]) {
				ans += 1;
				
				used[x] = true;
				
				int curr = 1;				
				
				for (int i = x + 1; i < N; i++) {
					if (!used[i]) {
						if (B[i] >= curr) {
							used[i] = true;
							curr++;
						}
					}
				}
			}
		}
		
		System.out.println(ans);
		
		in.close();
	}

}
