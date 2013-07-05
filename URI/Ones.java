import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        String buff = "";
        
        int N;

        while (true) {            
            try {
                buff = input.readLine();
            } catch (Exception e) {
                break;
            }

            if (buff == null || buff.equals("")) break;
            
            N = Integer.parseInt(buff);

            int cur = 1, cnt = 1;
            
            while (cur % N != 0) {
                cur = (cur * 10 + 1) % N;
                cnt += 1;
            }
            System.out.println(cnt);
        }
    }
}