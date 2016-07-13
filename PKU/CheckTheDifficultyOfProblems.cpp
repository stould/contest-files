#include <iostream>
#include <iomanip>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXT = 1010;
const int MAXN = 35;

int M, T, N;
double P[MAXT][MAXN];
double dp[MAXT][MAXN][MAXN][2];
int memo[MAXT][MAXN][MAXN][2];

int id = 1;
double func(int team, int pr, int used, int fine) {
    if (team == T) {
        if (fine) {
            return 1;
        } else {
            return 0;
        }
    } else if (pr == M) {
        if (used == 0) {
            return 0;
        } else {
            return func(team + 1, 0, 0, used >= N ? 1 : fine);
        }
    } else {
        double& ans = dp[team][pr][used][fine];

        if (memo[team][pr][used][fine] != id) {
            memo[team][pr][used][fine] = id;

            ans = 0;

            ans += (1 - P[team][pr]) * func(team, pr + 1, used, fine);
            ans += (P[team][pr]) * func(team, pr + 1, used + 1, fine);
        }

        return ans;
    }
}

int main(void) {
    while (cin >> M >> T >> N) {
        if (M + T + N == 0) break;
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < M; j++) {
                cin >> P[i][j];
            }
        }
        cout << fixed << setprecision(3) << func(0, 0, 0, 0) << endl;
        id++;
    }
    return 0;
}
