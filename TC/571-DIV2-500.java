import java.util.*;
import java.math.*;

public class FoxAndMp3Easy {
    public String[] playList(int n) {		
        String[] ans = new String[n];
		
        for(int i = 0; i < n; i++) ans[i] = (i + 1) + "";
		
        Arrays.sort(ans);
		
        for(int i = 0; i < n; i++) ans[i] += ".mp3";
		
        int end = Math.min(50, n);
        String[] go = new String[end];
		
        for(int i = 0; i < end; i++) go[i] = ans[i];
		
        return go;
				
    }
}

// Powered by FileEdit
