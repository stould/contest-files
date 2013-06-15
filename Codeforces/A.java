import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		String time = input.nextLine();

		int h = Integer.parseInt(time.substring(0, 2));
		int m = Integer.parseInt(time.substring(3, 5));

		for(int i = h; i <= 23; i++) {
			for(int j = m; j <= 59; j++) {
				String temp = i+":"+j;
				System.out.println(temp);
				if(isPalindrome(time) == true && !temp.equals(time)) {
					String hou = "";
					String min = "";
					
					if(String.valueOf(i).length() < 2) {
					    hou += "0" + i;
					 }
					 if(String.valueOf(j).length() < 2) {
					    min += "0" + j;
					 }
					System.out.println(hou + ":" + min);
					System.exit(0);
				}
				if(i == 23) {
					i = 0;
				}
				if(j == 59) {
					j = 0;
				}

			}
		}
	}
	public static boolean isPalindrome(String s) {
		StringBuilder build = new StringBuilder(s).reverse();
		return (build.toString().equals(s));
	}
}
