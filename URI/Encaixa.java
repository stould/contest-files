import java.util.*;

public class Encaixa {
    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	
	int n = in.nextInt();

	for(int i = 0; i < n; i++) {
	    String a = in.next(), b = in.next();

	    if(a.endsWith(b)) {
		System.out.println("encaixa");
	    } else {
		System.out.println("nao encaixa");
	    }	    
	}
    }
}