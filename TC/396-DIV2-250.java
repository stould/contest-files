import java.util.*;
import java.math.*;

public class VerifyCreditCard {
	public String checkDigits(String cardNumber) {
		int N = cardNumber.length();
		int[] digits = new int[N];
		
		for(int i = 0; i < N; i++) digits[i] = (int) cardNumber.charAt(i) - '0';
		
		if(N % 2 == 0) {
			for(int i = 0; i < N; i++) if(i % 2 == 0) digits[i] *= 2;		
		} else {
			for(int i = 0; i < N; i++) if(i % 2 != 0) digits[i] *= 2;
		}
		long sum = 0L;
		for(int i = 0; i < N; i++) {
			while(digits[i] > 0) {
				sum += digits[i];
				digits[i] /= 10;
			}
		}
		if(sum % 10L == 0) return "VALID";
		return "INVALID";
	}	
}


// Powered by FileEdit