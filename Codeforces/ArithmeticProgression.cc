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

const int MAXN = 100005;

int N;

Int A[MAXN];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];

    if (N == 1) {
        cout << "-1\n";
    } else {
        sort(A, A + N);

        set<Int> inc, dec;

        Int inc_l = 10001010101010100LL;
        Int inc_r = 0LL;

        bool all_eq = true;
        bool has_zero = false;

        for (int i = 0; i < N; i++) {
            if (i > 0) {
                inc.insert(A[i] - A[i - 1]);

                chmin(inc_l, (Int) A[i] - A[i - 1]);
                chmax(inc_r, (Int) A[i] - A[i - 1]);

                if (A[i] != A[i - 1]) {
                    all_eq = false;
                } else {
                    has_zero = true;
                }
            }
        }

        if (has_zero) {
            if (all_eq) {
				 cout << "1\n" << A[0] << "\n";
            } else {
                cout << "0\n";
            }
        } else {
            set<Int> ans;

            bool end = false;

            if (inc.size() == 1) {
                ans.insert(A[0] - inc_l);
                ans.insert(A[N - 1] + inc_l);

                if (N == 2 && (A[1] - A[0]) % 2 == 0) {
                    ans.insert(A[0] + (A[1] - A[0]) / 2);
                }
            } else if (inc.size() == 2) {
                int cnt = 0;
                for (int i = 1; i < N; i++) {
                    if (A[i] - A[i - 1] == inc_r && A[i - 1] + 2 * inc_l == A[i]) {
                        ans.insert(A[i - 1] + inc_l);
                        cnt += 1;
                    }
                }
                if (ans.size() > 1) ans.clear();
            }

            if (!end) {
                cout << ans.size() << "\n";

                for (set<Int>::iterator it = ans.begin(); it != ans.end(); it++) {
                    cout << *it << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
