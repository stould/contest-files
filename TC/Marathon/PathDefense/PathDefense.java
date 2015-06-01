import java.awt.Point;
import java.nio.file.Path;
import java.util.*;

/**
 * TopCoder Marathon Match - PathDefense
 * Created by aajjbb on 5/31/15.
 */
public class PathDefense {
    private char[][] board;
    private int money;
    private int creepHealth;
    private int creepMoney;
    private int[] towerType;
    private Tower[] towers;

    public int init(String[] init_board, int money, int creepHealth, int creepMoney, int[] towerType) {
        this.board = new char[init_board.length][];
        for (int i = 0; i < board.length; i++) {
            this.board[i] = init_board[i].toCharArray();
        }
        this.money = money;
        this.creepHealth = creepHealth;
        this.creepMoney = creepMoney;
        this.towerType = towerType;

        this.towers = new Tower[towerType.length / 3];

        for (int i = 0; i < towerType.length / 3; i++) {
            int i_range = towerType[i * 3];
            int i_power = towerType[i * 3 + 1];
            int i_cost  = towerType[i * 3 + 2];

            towers[i] = new Tower(i, i_range, i_power, i_cost);
        }

        Arrays.sort(this.towers);

        return 0;
    }
    /*
        First naive strategie:
        Sort available places to put a tower by their proximity to bases, then, put the che
     */
    public int[] placeTowers(int[] creep, int money, int[] baseHealth) {
        System.err.println("Running: real money = " + this.money + " method money: " + money);

        List<Integer> answer = new ArrayList<Integer>();
        List<InterestPoint> freePlaces = new ArrayList<InterestPoint>();

        Creeper[] creep_array = new Creeper[creep.length / 4];

        for (int i = 0; i < creep.length / 4; i++) {
            int i_id     = creep[i * 4 + 0];
            int i_health = creep[i * 4 + 1];
            int i_col    = creep[i * 4 + 2];
            int i_row    = creep[i * 4 + 3];

            creep_array[i] = new Creeper(i_id, i_row, i_col, i_health);
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == '#') {
                    int smallestDist = Integer.MAX_VALUE;

                    for (int a = 0; a < board.length; a++) {
                        for (int b = 0; b < board[a].length; b++) {
                            if (board[a][b] >= '0' && board[a][b] <= '9') {
                                int temp_dist = (a - i) * (a - i) + (b - j) * (b - j);

                                if (temp_dist < smallestDist) {
                                    smallestDist = temp_dist;
                                }
                            }
                        }
                    }
                    freePlaces.add(new InterestPoint(i, j, smallestDist));
                }
            }
       }

       Collections.sort(freePlaces);

       for (int j = 0; j < towers.length; j++) {
            if (this.money >= towers[j].cost) {
                answer.add(freePlaces.get(0).col);
                answer.add(freePlaces.get(0).row);
                answer.add(towers[j].id);
                this.money -= towers[j].cost;
                this.board[freePlaces.get(0).row][freePlaces.get(0).col] = 'X';
                break;
            }
        }

        int[] answerAsArray = new int[answer.size()];

        for (int i = 0; i < answer.size(); i++) {
            answerAsArray[i] = (int) answer.get(i);
        }

        return answerAsArray;
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

            for (int i=0; i < B; i++) {
                baseHealth[i] = Integer.parseInt(input.nextLine());
            }
            int[] ret = pathDefense.placeTowers(creep, money, baseHealth);
            System.out.println(ret.length);
            for (int i=0; i < ret.length; i++) {
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

        public Creeper() {

        }

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

        public Tower() {

        }

        public Tower(int id, int range, int power, int cost) {
            this.id = id;
            this.range = range;
            this.power = power;
            this.cost = cost;
        }

        @Override
        public int compareTo(Object o) {
            Tower other = (Tower) o;
/*
            long coef = this.range * this.power * this.cost;
            long o_coef = other.range * other.power * other.cost;

            if (coef > o_coef) {
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
        */
            return this.power > other.power ? -1 : 1;
        }
    }

    static class InterestPoint implements Comparable {
        public int row;
        public int col;
        public int closestBase;

        public  InterestPoint() {

        }

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
}