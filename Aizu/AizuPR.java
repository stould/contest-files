import java.util.*;

public class AizuPR {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);

        int N = Integer.parseInt(input.nextLine());

        for(int i = 0; i < N; i++) {
            String s = input.nextLine().replaceAll("Hoshino", "Hoshina");

            System.out.println(s);
        }
    }
}
