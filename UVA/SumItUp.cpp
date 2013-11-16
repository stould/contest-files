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

typedef long long Int;
typedef unsigned uint;

int T, N;

int main(void) {
//    freopen("i.in", "r", stdin);
    int i, j;

    for ( ; ; ) {
        T = in();
        N = in();

        if (T + N == 0) break;

        vector<int> x(N);

        for (i = 0; i < N; i++) x[i] = in();

        printf("Sums of %d:\n", T);

        int cnt = 0;
        set<vector<int> > vs;
        set<vector<int> >::reverse_iterator it;

        for (i = 0; i < (1 << N); i++) {
            int sum = 0;

            for (j = 0; j < N; j++) {
                if ((i >> j) & 1) {
                    sum += x[j];
                }
            }

            if (sum == T) {
                vector<int> ans;
                for (j = 0; j < N; j++) {
                    if ((i >> j) & 1) {
                        ans.push_back(x[j]);
                    }
                }
                vs.insert(ans);
            }
        }

        if (vs.empty()) {
            printf("NONE\n");
        } else {
            for (it = vs.rbegin(); it != vs.rend(); it++) {
                vector<int> vt = *it;
                for (j = 0; j < (int) vt.size(); j++) {
                    printf("%d", vt[j]);
                    if (j == (int) vt.size() - 1) {
                        printf("\n");
                    } else {
                        printf("+");
                    }
                }
            }
        }
    }
    return 0;
}

