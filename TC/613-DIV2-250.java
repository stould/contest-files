import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TaroString {
	public String getAnswer(String S) {
		for (char c = 'A'; c <= 'Z'; c++) {
			if (c == 'A' || c == 'C' || c == 'T') continue;
			S = S.replace(""+ c, "");
		}	
		return S.equals("CAT") ? "Possible" : "Impossible";
	}
}
//Powered by [KawigiEdit] 2.0!
