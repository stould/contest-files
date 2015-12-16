import java.util.*;
import java.util.stream.StreamSupport;

import static java.lang.Integer.lowestOneBit;
import static java.lang.Integer.parseInt;

public class Main {
    public final int INF = 100010100;

    public int N;
    public int M;
    public int balls;

    public char[][] start;
    public char[][] target;

    public int targetDist[][][];

    public int dx[] = {-1, 1,  0, 0};
    public int dy[] =  {0, 0, -1, 1};

    public String dir[] = {"3", "1", "0", "2"};

    public boolean isBall(char c) {
        return c >= '0' && c <= '9';
    }

    public String[] restorePattern(String[] start, String[] target) {
        this.N = start.length;
        this.M = start[0].length();

        this.start  = new char[N][];
        this.target = new char[N][];

        this.targetDist = new int[15][this.N][this.M];

        List<String> answerList = new ArrayList<>();
        Set<Path> memo = new HashSet<>();

        for (int i = 0; i < N; i++) {
            this.start[i]  = start[i].toCharArray();
            this.target[i] = target[i].toCharArray();

            for (int j = 0; j < 15; j++) {
                Arrays.fill(this.targetDist[j][i], INF);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (isBall(this.start[i][j])) {
                    balls += 1;
                }
                if (isBall(this.target[i][j])) {
                    runTargetDist(i, j);
                }
            }
        }

        printTargetDist();

        int best = Integer.MAX_VALUE;

        //main loop
        for (int run = 0; run < 20 * balls && answerList.size() < 20 * balls; run++) {
            List<Path> paths = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (isBall(this.start[i][j]) && this.start[i][j] != this.target[i][j]) {
                        paths.add(bfs(i, j));
                    }
                }
            }
            //System.err.println(paths.size());
            Collections.sort(paths);

            int beg = 0;

            while (beg < paths.size() && memo.contains(paths.get(beg))) {
                beg += 1;
            }

            if (!paths.isEmpty() && beg < paths.size()) {
                //System.err.println(paths.get(beg).std_i + " " + paths.get(beg).std_j + " = " + paths.get(beg).end_i + " " + paths.get(beg).end_j + " " + paths.get(beg).path.size());

                for (int i = 0; i < paths.get(beg).path.size(); i++) {
                    answerList.add(paths.get(beg).path.get(i));
                    //System.err.println(paths.get(beg).path.get(i));
                }
                //System.err.println(paths.get(0).std_i + " " + paths.get(0).std_j + " = " + paths.get(0).end_i + " " + paths.get(0).end_j);
                //System.err.println(this.start[paths.get(0).std_i][paths.get(0).std_j]);

                this.start[paths.get(beg).end_i][paths.get(beg).end_j] = this.start[paths.get(beg).std_i][paths.get(beg).std_j];
                this.start[paths.get(beg).std_i][paths.get(beg).std_j] = '.';

                memo.add(paths.get(beg));
             //   printMaze();
            }
            //System.err.println(run);
        }

        String[] answer = new String[Math.min(20 * balls, answerList.size())];

        for (int i = 0; i < Math.min(20 * balls, answerList.size()); i++) {
            answer[i] = answerList.get(i);
        }

        System.err.println(Arrays.deepToString(answer));

        return answer;
    }

    public void printTargetDist() {
        for (int i = 0; i < this.N; i++) {
            for (int j = 0; j < this.M; j++) {
                System.err.print(this.targetDist[0][i][j] + " ");
            }
            System.err.println();
        }
        System.err.println();
    }

    public void printMaze() {
        for (int i = 0; i < this.N; i++) {
            for (int j = 0; j < this.M; j++) {
                System.err.print(this.start[i][j] + " ");
            }
            System.err.println();
        }
        System.err.println();
    }

    public boolean insideBoundaries(int i, int j) {
        return i >= 0 && i < this.N && j >= 0 && j < this.M;
    }


    public void runTargetDist(int si, int sj) {
        int val = this.target[si][sj] - '0';

        Queue<Integer> q = new LinkedList<>();

        this.targetDist[val][si][sj] = 0;

        q.add(si);
        q.add(sj);

        while (!q.isEmpty()) {
            int curr_i = q.poll();
            int curr_j = q.poll();

            for (int i = 0; i < 4; i++) {
                int next_i = curr_i + dx[i];
                int next_j = curr_j + dy[i];

                if (insideBoundaries(next_i, next_j) && this.target[next_i][next_j] != '#') {
                    if (this.targetDist[val][next_i][next_j] > this.targetDist[val][curr_i][curr_j] + 1) {
                        this.targetDist[val][next_i][next_j] = this.targetDist[val][curr_i][curr_j] + 1;
                        q.add(next_i);
                        q.add(next_j);
                    }
                }
            }
        }
    }

    /*
    //initial greedy idea

    Run bfs starting from a ball position
    Return the best current sequence to put ball(si, sj) in a proper hole or in a nearest position
     */
    Path bfs(int si, int sj) {
        Path[][] dist = new Path[this.N][this.M];
        Path ans = new Path();

        int val = this.start[si][sj] - '0';
        int outCome = Integer.MAX_VALUE;

        for (int i = 0; i < this.N; i++) {
            for (int j = 0; j < this.M; j++) {
                dist[i][j] = new Path();

                dist[i][j].std_i = si;
                dist[i][j].std_j = sj;

                dist[i][j].end_i = i;
                dist[i][j].end_j = j;
            }
        }

        dist[si][sj].len = 0;

        Queue<Integer> q = new LinkedList<>();

        q.add(si);
        q.add(sj);

        char before = this.start[si][sj];
        this.start[si][sj] = '.';

        while (!q.isEmpty()) {
            int curr_i = q.poll();
            int curr_j = q.poll();

            for (int i = 0; i < 4; i++) {
                int next_i = curr_i + dx[i];
                int next_j = curr_j + dy[i];

                while (true) {
                    if (!insideBoundaries(next_i, next_j) || this.start[next_i][next_j] != '.') {
                        next_i -= dx[i];
                        next_j -= dy[i];
                        break;
                    }

                    next_i += dx[i];
                    next_j += dy[i];
                }

                if (dist[next_i][next_j].len > dist[curr_i][curr_j].len + 1) {
                    dist[next_i][next_j].len = dist[curr_i][curr_j].len + 1;

                    dist[next_i][next_j].path = new ArrayList<>(dist[curr_i][curr_j].path);

                    String d = curr_i + " " + curr_j + " " + this.dir[i];
                    dist[next_i][next_j].path.add(d);

                    q.add(next_i);
                    q.add(next_j);
                }
            }
        }

        for (int i = 0; i < this.N; i++) {
            for (int j = 0; j < this.M; j++) {
                if (this.start[i][j] == '.' && this.target[i][j] == this.start[si][sj]) {
                    int currOutcome = (this.targetDist[val][i][j] + 1);

                    if (dist[i][j].path.size() == 0) {
                        currOutcome = INF;
                    } else {
                        currOutcome += dist[i][j].path.size();
                    }

                    if (currOutcome < outCome) {
                        outCome = currOutcome;
                        ans = dist[i][j];
                    }
                }
            }
        }

        this.start[si][sj] = before;

        return ans;
    }

    class Path implements Comparable<Path> {
        int std_i, std_j;
        int end_i, end_j;
        int len;
        List<String> path;

        public Path() {
            this.len = 1000000;
            this.path = new ArrayList<String>();
        }

        @Override
        public int hashCode() {
            return path.hashCode();
        }

        @Override
        public int compareTo(Path path) {
            //System.err.println(std_i + " " + std_j  + " " + start[std_i][std_j]);
            //System.err.println(path.std_i + " " + path.std_j  + " " + start[path.std_i][path.std_j]);

            int valA = start[std_i][std_j] - '0';
            int valB = start[path.std_i][path.std_j] - '0' ;

            if (valA < 0) valA = 10;
            if (valB < 0) valB = 10;

            if (targetDist[valA][end_i][end_j] < targetDist[valB][path.end_i][path.end_j]) {
                return -1;
            } else if (targetDist[valA][end_i][end_j] == targetDist[valB][path.end_i][path.end_j]) {
                if (len < path.len) {
                    return -1;
                } else if (len == path.len) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                return 1;
            }
        }
    }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Main main = new Main();

        int H = parseInt(input.nextLine());

        String[] start = new String[H];

        for (int i = 0; i < H; i++) {
            start[i] = input.nextLine();
        }

        H = parseInt(input.nextLine());

        String[] target = new String[H];

        for (int i = 0; i < H; i++) {
            target[i] = input.nextLine();
        }

        String[] ret = main.restorePattern(start, target);

        System.out.println(ret.length);

        for (int i = 0; i < ret.length; i++) {
            System.out.println(ret[i]);
        }
        System.out.flush();;
    }
}
