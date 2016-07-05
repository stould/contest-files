#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int INF = 1000000;
const int MAX_DEPTH = 4;
const int MAXN = 9;

int globalBest = -(2 * INF);
vector<int> globalPlays;

int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};

int K;
map<int, int> value; //value to stream sizes

int opposite(int a) {
    return a == 1 ? 2 : 1;
}

bool inside(int a, int b) {
    return a >= 0 && b >= 0 && a < 7 && b < 8;
}

//overall/can_win
pair<int, bool> run(int turn, vector<vector<int> > field) {
    int ans = 0;
    bool seen_4 = false;

    for (int a = 0; a < 7; a++) {
        for (int b = 0; b < 8; b++) {
            if (field[a][b] == turn) {
                for (int k = 0; k < 8; k++) {
                    int pa = a;
                    int pb = b;

                    int len = 1;

                    while (true) {
                        pa += dx[k];
                        pb += dy[k];

                        if (!inside(pa, pb) || field[pa][pb] != turn) {
                            break;
                        }

                        len += 1;
                    }

                    ans += value[len];

                    if (len >= 4) {
                        seen_4 = true;
                    }
                }
            }
        }
    }

    return make_pair(ans, seen_4);
}

void rec(int depth, int initial, int turn, vector<vector<int> > field, vector<int> play) {
    if (depth == MAX_DEPTH) {
        int outcome = 0;

        pair<int, bool> out_mine = run(initial, field);
        pair<int, bool> out_oppo = run(opposite(initial), field);

        //win position
        if (out_oppo.second) {
            outcome = -INF;
        } else {
            if (out_mine.second) {
                outcome = INF - out_oppo.first;
            } else {
                outcome = out_oppo.first - out_mine.first;
            }
        }

        if (outcome > globalBest) {
            globalBest = outcome;
            globalPlays.clear();
            globalPlays.push_back(play[0]);
        }
    } else {
        for (int j = 0; j < 8; j++) {
            int i = -1;

            while (i + 1 <= 6 && field[i + 1][j] == 0) {
                i += 1;
            }

            if (i == -1) {
                continue;
            }

            vector<int> new_play = play;
            vector<vector<int> > new_field = field;

            new_field[i][j] = turn;
            new_play.push_back(j);

            rec(depth + 1, initial, turn == 1 ? 2 : 1, new_field, new_play);
        }
    }
}


int main(void) {
    value[1] = 1;
    value[2] = 3;
    value[3] = 1000;
    value[4] = 100000;

    vector<vector<int> > field(7, vector<int>(8));

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> field[i][j];
        }
    }

    cin >> K;
    
    for (int j = 0; j < 8; j++) {
        int i = -1;
        
        while (i + 1 <= 6 && field[i + 1][j] == 0) {
            i += 1;
        }
        
        if (i == -1) {
            continue;
        }

        vector<vector<int> > other_field;

        other_field[i][j] = K;

        if (has_tree(field, opposite(K))) {

        }
    }
            

    rec(0, K, K, field, vector<int>());

    srand(time(NULL));

    for (int i = 0; i < globalPlays.size(); i++) {
        //cout << globalPlays[i][0].second << "\n";
    }
    
    int pos = rand() % globalPlays.size();
    cout << globalPlays[pos] << "\n";

    return 0;
}
