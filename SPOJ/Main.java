import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
    int amigos = 0, n = 0, i = 0;
    while(true) {
      n = Integer.parseInt(input.nextLine().split("\\s")[0]);
      amigos = Integer.parseInt(input.nextLine().split("\\s")[1]);
      
      if(n == 0 && amigos == 0) { break; }

      BigInteger t = new BigInteger("0");

      while(n > 0) {
        String temp = input.nextLine();
        t.add(new BigInteger(temp));
      }
      System.out.println("Bill #" + ++i + " costs " + t.toString() + ": each friend should pay " + t.divide(new BigInteger(""+amigos)).toString());
      System.out.println();
    }
  }
}
