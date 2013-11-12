import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        String str = null;

        while (true) {
            str = input.readLine();

            if (str.equals("DONE")) break;

            str = str.replaceAll("[^A-Za-z]", "");
            str = str.toLowerCase();

            if (func(str)) {
                System.out.println("You won't be eaten!");
            } else {
                System.out.println("Uh oh..");
            }
        }
    }
    public static boolean func(String str) {
        int i;
        int N = str.length();

        for (i = 0; i < N / 2; i++) {
            if (str.charAt(i) != str.charAt(N - i - 1)) {
                return false;
            }
        }

        return true;
    }
}