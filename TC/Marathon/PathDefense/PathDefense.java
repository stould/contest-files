import java.awt.Point;
import java.util.*;

/**
 * TopCoder Marathon Match - PathDefense
 * Created by aajjbb on 5/31/15.
 */
public class PathDefense {
    private char[][] board;
    public int baseMoney;
    private int creepHealth;
    private int creepMoney;
    private int[] towerType;
    private List<Tower> towers;
    private int[] seen;
    public boolean isDense;
    public List<Point> availableSpots;
    public List<Base> bases;
    public int[][] distanceFromPath;
    public int[][] pathNeighbours;
    public int[][] reachableEntrances;
    public List<List<Point>> closestFreePoints;

    private int[] dx = {0, 0, -1, 1};
    private int[] dy = {-1, 1, 0, 0};

    /*
        Optimizing score, and then, speed
     */

    public int init(String[] init_board, int money, int creepHealth, int creepMoney, int[] towerType) {
        this.board = new char[init_board.length][];
        this.distanceFromPath = new int[init_board.length][];
        this.pathNeighbours = new int[init_board.length][];
        this.reachableEntrances = new int[init_board.length][];
        this.bases = new ArrayList<Base>();
        this.closestFreePoints = new ArrayList<List<Point>>();
        this.availableSpots = new ArrayList<Point>();

        for (int i = 0; i < board.length; i++) {
            this.board[i] = init_board[i].toCharArray();
            this.distanceFromPath[i] = new int[this.board[i].length];
            this.pathNeighbours[i] = new int[this.board[i].length];
            this.reachableEntrances[i] = new int[this.board[i].length];

            for (int j = 0; j < this.board[i].length; j++) {
                int free = 0;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && nj >= 0 && ni < init_board.length && nj < init_board[ni].length()) {
                        if (init_board[ni].charAt(nj) == '.') {
                            free += 1;
                        }
                    }
                }
                this.pathNeighbours[i][j] = free;
                if (this.board[i][j] >= '0' && this.board[i][j] <= '9') {
                    if (free != 0) {
                        this.bases.add(new Base(this.board[i][j] - '0', i, j));
                    }
                } else if (this.board[i][j] == '#') {
                    availableSpots.add(new Point(i, j));
                }
            }
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < this.board[i].length; j++) {
                if (this.board[i][j] == '.') {
                    shortestPathFromAvailableTowerToPath(i, j);
                } else {
                    if (this.board[i][j] >= '0' && this.board[i][j] <= '9') {
                        this.reachableEntrances[i][j] = numberOfEntrancesReachableBy(i, j);
                    }
                }
            }
        }

        this.seen = new int[this.bases.size()+1];

        for (int i = 0; i < this.bases.size(); i++) {
            this.closestFreePoints.add(new ArrayList<Point>());

            int base_x = this.bases.get(i).row;
            int base_y = this.bases.get(i).col;

            Collections.sort(availableSpots, (p1, p2) -> {
                long d1 = (long) (Math.pow((p1.x - base_x), 2) + Math.pow((p1.y - base_y), 2)) - distanceFromPath[p1.x][p1.y];
                long d2 = (long) (Math.pow((p2.x - base_x), 2) + Math.pow((p2.y - base_y), 2)) - distanceFromPath[p2.x][p2.y];

                if (d1 < d2) {
                    return -1;
                } else {
                    return +1;
                }
            });
            for (int j = 0; j < Math.min(60, availableSpots.size()); j++) {
                this.closestFreePoints.get(this.closestFreePoints.size() - 1).add(availableSpots.get(j));
            }
        }

        this.baseMoney = money;
        this.creepHealth = creepHealth;
        this.creepMoney = creepMoney;
        this.towerType = towerType;

        this.towers = new ArrayList<Tower>();

        for (int i = 0; i < towerType.length / 3; i++) {
            int i_range = towerType[i * 3];
            int i_power = towerType[i * 3 + 1];
            int i_cost = towerType[i * 3 + 2];

            //System.err.println(i_power + " " + i_range + " " + i_cost);

            towers.add(new Tower(i, i_range, i_power, i_cost));
        }

        Collections.sort(towers);

        this.isDense = isDense();

        if (this.isDense) {
            //System.err.println("Dense");
        }

        for (int i = 0; i < this.towers.size(); i++) {
            //System.err.println("Tower order = " + this.towers.get(i).power + " " + this.towers.get(i).range + " " + this.towers.get(i).cost);
        }

        return 0;
    }

    /*
        First naive strategie:
        Sort available places to put a tower by their proximity to bases, then, put the che
     */
    public int[] placeTowers(int[] creep, int money, int[] baseHealth) {
        Collections.sort(this.availableSpots, new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2) {
                if (pathNeighbours[p1.x][p1.y] > pathNeighbours[p2.x][p2.y]) {
                    return -1;
                } else if (pathNeighbours[p1.x][p1.y] == pathNeighbours[p2.x][p2.y]) {
                    return +0;
                } else {
                    return +1;
                }
            }
        });
        List<Integer> answer = new ArrayList<Integer>();

        Creeper[] creep_array = new Creeper[creep.length / 4];

        for (int i = 0; i < creep.length / 4; i++) {
            int i_id = creep[i * 4 + 0];
            int i_health = creep[i * 4 + 1];
            int i_col = creep[i * 4 + 2];
            int i_row = creep[i * 4 + 3];

            creep_array[i] = new Creeper(i_id, i_row, i_col, i_health);
        }

        if (isDense) {
            answer = dense(money, baseHealth);
        } else {
            answer = sparse(money);
        }

        int[] answerAsArray = new int[answer.size()];

        for (int i = 0; i < answer.size(); i++) {
            answerAsArray[i] = (int) answer.get(i);
        }

        return answerAsArray;
    }

    public List<Integer> sparse(int money) {
        List<Integer> answer = new ArrayList<>();

        for (int i = 0; i < Math.min(this.bases.size() * 20, this.availableSpots.size()); i++) {
            int pi = this.availableSpots.get(i).x;
            int pj = this.availableSpots.get(i).y;

            if (this.pathNeighbours[pi][pj] == 0) {
                break;
            }

            if (this.board[pi][pj] != '#') continue;

            for (int k = 0; k < 1; k++) {
                if (this.towers.get(k).cost <= money) {
                    answer.add(pj);
                    answer.add(pi);
                    answer.add(this.towers.get(k).id);
                    money -= this.towers.get(k).cost;
                    this.board[pi][pj] = 'X';
                    break;
                }
            }
        }
        return answer;
    }

    public List<Integer> dense(int money, int[] baseHealth) {
        List<Integer> answer = new ArrayList<>();

        for (int i = 0; i < this.bases.size(); i++) {
            int multFactor = this.reachableEntrances[this.bases.get(i).row][this.bases.get(i).col];
            if (this.seen[this.bases.get(i).id] >= 5 * multFactor && baseHealth[this.bases.get(i).id] == 1000) continue;
            if (this.seen[this.bases.get(i).id] > 35) continue;
            for (int j = 0; j < this.closestFreePoints.get(i).size(); j++) {
                int pi = (int) this.closestFreePoints.get(i).get(j).getX();
                int pj = (int) this.closestFreePoints.get(i).get(j).getY();

                if (this.board[pi][pj] != '#') continue;;

                boolean new_tower = false;

                for (int k = 0; k < 1; k++) {
                    if (this.towers.get(k).cost <= money) {
                        this.seen[this.bases.get(i).id] += 1;
                        answer.add(pj);
                        answer.add(pi);
                        answer.add(this.towers.get(k).id);
                        money -= this.towers.get(k).cost;
                        this.board[pi][pj] = 'X';
                        new_tower = true;
                        break;
                    }
                }
                if (new_tower) {
                    break;
                }
            }
        }
        return answer;
    }

    public boolean isDense() {
        double mean = (this.board.length * this.board.length - this.availableSpots.size()) * 100.0 / (this.board.length * this.board.length);
        return mean <= 40.0;
    }

    public int numberOfEntrancesReachableBy(int row, int col) {
        Queue<Point> queue = new LinkedList<>();
        queue.offer(new Point(row, col));

        int[][] currDist = new int[this.board.length][this.board[0].length];

        for (int i = 0; i < this.board.length; i++) {
            Arrays.fill(currDist[i], Integer.MAX_VALUE);
        }

        currDist[row][col] = 0;

        int ans = 0;

        while (!queue.isEmpty()) {
            int curr_row = queue.peek().x;
            int curr_col = queue.peek().y;
            queue.poll();

            for (int i = 0; i < 4; i++) {
                int ni = curr_row + dx[i];
                int nj = curr_col + dy[i];

                if (insideBoard(ni, nj)) {
                    if (this.board[ni][nj] == '.') {
                        if (currDist[ni][nj] > currDist[curr_row][curr_col] + 1) {
                            currDist[ni][nj] = currDist[curr_row][curr_col] + 1;
                            queue.offer(new Point(ni, nj));
                        }
                    }
                } else {
                    ans += 1;
                }
            }
        }
        return ans;
    }

    public boolean insideBoard(int row, int col) {
        return row >= 0 && col >= 0 && row < this.board.length && col < this.board[0].length;
    }

    public void shortestPathFromAvailableTowerToPath(int row, int col) {
        Queue<Point> queue = new LinkedList<>();
        queue.offer(new Point(row, col));

        int[][] currDist = new int[this.board.length][this.board[0].length];

        for (int i = 0; i < this.board.length; i++) {
            Arrays.fill(currDist[i], Integer.MAX_VALUE);
        }

        currDist[row][col] = 0;

        int best = Integer.MAX_VALUE;

        while (!queue.isEmpty()) {
            int curr_row = queue.peek().x;
            int curr_col = queue.peek().y;
            queue.poll();

            for (int i = 0; i < 4; i++) {
                int ni = curr_row + dx[i];
                int nj = curr_col + dy[i];

                if (insideBoard(ni, nj)) {
                    if (this.board[ni][nj] == '#') {
                        if (currDist[ni][nj] > currDist[curr_row][curr_col] + 1) {
                            currDist[ni][nj] = currDist[curr_row][curr_col] + 1;
                            queue.offer(new Point(ni, nj));
                        }
                    } else if (this.board[ni][nj] == '.') {
                        best = Math.min(best, currDist[curr_row][curr_col] + 1);
                    }
                }
            }
        }

        this.distanceFromPath[row][col] = best;
    }

    public static void main(String[] args) {
        PathDefense pathDefense = new PathDefense();

        Scanner input = new Scanner(System.in);
        int N = Integer.parseInt(input.nextLine());
        int money = Integer.parseInt(input.nextLine());

        String[] board = new String[N];

        for (int i = 0; i < N; i++) {
            board[i] = input.nextLine();
        }
        int creepHealth = Integer.parseInt(input.nextLine());
        int creepMoney = Integer.parseInt(input.nextLine());
        int NT = Integer.parseInt(input.nextLine());

        int[] towerType = new int[NT];

        for (int i = 0; i < NT; i++) {
            towerType[i] = Integer.parseInt(input.nextLine());
        }

        pathDefense.init(board, money, creepHealth, creepMoney, towerType);

        for (int t = 0; t < 2000; t++) {
            int testCaseMoney = Integer.parseInt(input.nextLine());
            int NC = Integer.parseInt(input.nextLine());
            int[] creep = new int[NC];
            for (int i = 0; i < NC; i++) {
                creep[i] = Integer.parseInt(input.nextLine());
            }
            int B = Integer.parseInt(input.nextLine());
            int[] baseHealth = new int[B];

            for (int i = 0; i < B; i++) {
                baseHealth[i] = Integer.parseInt(input.nextLine());
            }
            int[] ret = pathDefense.placeTowers(creep, testCaseMoney, baseHealth);
            System.out.println(ret.length);
            for (int i = 0; i < ret.length; i++) {
                System.out.println(ret[i]);
            }
            System.out.flush();
        }
    }

    static class Creeper {
        public int id;
        public int row;
        public int col;
        public int health;

        public Creeper(int id, int row, int col, int health) {
            this.id = id;
            this.row = row;
            this.col = col;
            this.health = health;
        }
    }

    static class Tower implements Comparable {
        public int id;
        public int range;
        public int power;
        public int cost;

        public Tower(int id, int range, int power, int cost) {
            this.id = id;
            this.range = range;
            this.power = power;
            this.cost = cost;
        }

        @Override
        public int compareTo(Object o) {
            Tower other = (Tower) o;

            double coef = this.power * this.range / (double) this.cost;
            double o_coef = other.power * other.range / (double) other.cost;

            if (coef >= o_coef) {
                return -1;
            } else if (coef == o_coef) {
                if (this.cost <= other.cost) {
                    return -1;
                } else {
                    return +1;
                }
            } else {
                return +1;
            }
        }
    }


    static class InterestPoint implements Comparable {
        public int row;
        public int col;
        public int closestBase;

        public InterestPoint(int row, int col, int closestBase) {
            this.row = row;
            this.col = col;
            /*
            Distance is (a - b) * (a - b) + (c - d) * (c - d)
            I'm not squaring
             */
            this.closestBase = closestBase;
        }

        @Override
        public int compareTo(Object o) {
            InterestPoint casted = (InterestPoint) o;

            if (this.closestBase < casted.closestBase) {
                return -1;
            } else {
                return +1;
            }
        }
    }

    static class Base {
        public int id;
        public int row;
        public int col;

        public Base(int id, int row, int col) {
            this.id = id;
            this.row = row;
            this.col = col;
        }
    }
}
