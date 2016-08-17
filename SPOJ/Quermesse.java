import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String n = "";
        int t = 0;
        while(true) {
            n = input.readLine();
            if(n.equals("0")) { break; }
			
            String[] temp = input.readLine().split("\\s");
			
            for(int i = 0; i < temp.length; i++) {
                if(temp[i].equals(String.valueOf(i + 1))) {
                    System.out.println("Teste " + ++t + "\n" + temp[i] + "\n");
                    break;
                }
            }
        }
    }
}
 
 
 
