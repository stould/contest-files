import java.util.*;

public class HockeyA {
   public static void main(String[] args) throws IOException {
      BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
      int a = input.read();
      int count = 0;
	
      while(input.ready()) {
         if(count == a) System.out.println(input.readLine());
	    count++;
	}	
   }
}
