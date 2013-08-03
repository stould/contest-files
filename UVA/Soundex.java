import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        String buff;

        char[] f = new char[30];

        f[encode('B')] = '1';
        f[encode('F')] = '1';
        f[encode('P')] = '1';
        f[encode('V')] = '1';

        f[encode('C')] = '2';
        f[encode('G')] = '2';
        f[encode('J')] = '2';
        f[encode('K')] = '2';
        f[encode('Q')] = '2';
        f[encode('S')] = '2';
        f[encode('X')] = '2';
        f[encode('Z')] = '2';

        f[encode('D')] = '3';
        f[encode('T')] = '3';

        f[encode('L')] = '4';

        f[encode('M')] = '5';
        f[encode('N')] = '5';

        f[encode('R')] = '6';

        while (true) {
            buff = in.readLine();

            if (buff == null) break;
            
            int i, N = buff.length();
            String ans = "";

            for (i = 0; i < N; i++) {
                if (Character.isLetter(buff.charAt(i))) {
                    ans += f[encode(buff.charAt(i))];
                }
            }

            for (i = 0; i < ans.length() - 1; i++) {
                if (ans.charAt(i) == ans.charAt(i+1)) {
                    ans = ans.substring(0, i) + ans.substring(i + 1);
                    i = 0;
                }
            }
            System.out.println(ans);
        }
    }
    public static int encode(char c) {
        return c - 'A';
    }
}