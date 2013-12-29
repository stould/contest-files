import java.util.*;
import java.math.*;

public class PalindromizationDiv2 {
	public int getMinimumCost(int X) {
		int cheap = Integer.MAX_VALUE;
		if(isPalindrome(X)) return 0;
		
		SortedSet<Integer> palindromes = allPalindromic(X*100);
		
		for(Integer i: palindromes) {
			cheap = Math.min(cheap, Math.abs(X-i));
			if(i > X) break;
		}
		return cheap;
	}
	public boolean isPalindrome(int n) {
		String s = ""+n;
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) != s.charAt(s.length() - i - 1)) return false;
		}
		return true;
	}
	public SortedSet<Integer> allPalindromic(int limit) {
	    SortedSet<Integer> result = new TreeSet<Integer>();

    	for (int i = 0; i <= 9 && i <= limit; i++) {
       		result.add(i);
       	}

	    boolean cont = true;
	    for (int i = 1; cont; i++) {
	        StringBuffer rev = new StringBuffer("" + i).reverse();
	        cont = false;
	        for (String d : "0123456789".split("")) {
	            int n = Integer.parseInt("" + i + d + rev);
	            if (n <= limit) {
	                cont = true;
	                result.add(n);
	            }
	        }
	    }
		return result;
	}
}


// Powered by FileEdit