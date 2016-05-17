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

const int MAXN = 16;
const int MAX_DEPTH = 50;

int T, N, P, Q;
vector<int> G[MAXN];
bool mark[MAXN][MAX_DEPTH];
double dp[MAXN][MAX_DEPTH];
int V[MAXN][MAXN], deg[MAXN];

double func(int curr, int depth, int goal) {
    if (curr == goal) {
        return 1;
    } else if (depth > MAX_DEPTH) {
        return 0;
    } else {
        if (!mark[curr][depth]) {
            mark[curr][depth] = true;

            dp[curr][depth] = 0;
            
            for (int i = 0; i < (int) G[curr].size(); i++) {
                int next = G[curr][i];

                dp[curr][depth] += (V[curr][next] / (double) deg[curr]) * func(next, depth + 1, goal);
            }
        }

        return dp[curr][depth];
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> P >> Q;

        for (int i = 0; i <= N; i++) {
            G[i].clear();
            deg[i] = 0;
        }

        memset(V, 0, sizeof(V));

        for (int i = 0; i < N - 1; i++) {
            int A, B, C;

            cin >> A >> B >> C;

            deg[A] += 1;
            deg[B] += 1;

            V[A][B] = V[B][A] = C;

            G[A].push_back(B);
            G[B].push_back(A);
        }

        memset(mark, false, sizeof(mark));

        cout << fixed << setprecision(5) << func(P, 0, Q) << "\n";
    }
    return 0;
}
