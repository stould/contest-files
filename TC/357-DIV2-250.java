import java.util.*;

public class MnemonicMemory {
	public String getPhrase(String number, String[] d) {
		String s = ""+number, ret = "";
		int N = number.length();
		Arrays.sort(d);
		int temp = 0;
		for(int x = 0; x < N; x++) {
			for(int i = 0; i < d.length; i++) {
				if(d[i].length() == Integer.parseInt(s.charAt(x)+"")) {
					ret += d[i] + " ";
					d[i] = "";
					temp++;
					break;
				}
			}
			if(temp == N) break;
		}
		return ret.trim();
	}
}


// Powered by FileEdit