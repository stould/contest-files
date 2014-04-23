import java.util.*;
import java.io.*;

public class SearchingForNessy {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(in.readLine());

		for (int t = 0; t < N; t++) {
			String[] arr = in.readLine().split(" ");

			int A = Integer.parseInt(arr[0]);
			int B = Integer.parseInt(arr[1]);

			System.out.println(((int) A / 3) * ((int) B / 3));
		}
		in.close();
	}
}
