import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import static java.lang.Integer.parseInt;

/**
 * Created by aajjbb on 6/29/15.
 */
public class PegJumping {
    private static String[] getMoves(int[] pegValue, String[] board) {
        int N = board.length;
        int M = pegValue.length;

        List<String> answerAsList = new ArrayList<>();



        String[] ans = new String[answerAsList.size()];

        for (int i = 0; i < ans.length; i++) {
            ans[i] = answerAsList.get(i);
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int N, M;
        int[] pegValue;
        String[] board;


        M = parseInt(input.nextLine());

        pegValue = new int[M];

        for (int i = 0; i < M; i++) {
            pegValue[i] = parseInt(input.nextLine());
        }

        N = parseInt(input.nextLine());

        board = new String[N];

        for (int i = 0; i < N; i++) {
            board[i] = input.nextLine();
        }

        String[] ret = getMoves(pegValue, board);

        System.out.println(ret.length);

        for (int i = 0; i < ret.length; i++){
            System.out.println(ret[i]);
        }

        System.out.flush();
    }
}
