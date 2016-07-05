import java.util.*;
import java.math.*;

public class MultiNumber {
	public String check(int number) {
		String num = "" + number;
		
		if(number < 10) return "NO";
		
		for(int i = 0; i < num.length(); ++i) {
			int prod_a = 1, prod_b = 1;
			for(int k = 0; k <= i; k++) prod_a *= num.charAt(k) - '0'; 	
			for(int k = i+1; k < num.length(); k++) prod_b *= num.charAt(k) - '0';
			
			if(prod_a == prod_b) return "YES";
		}		
		return "NO";
	}	
}


// Powered by FileEdit
