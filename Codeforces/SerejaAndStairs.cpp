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
int X[MAXN];
int cnt[5050];

int main(void) {
    N = in();

    memset(cnt, 0, sizeof(cnt));
    bool single = true;

    for (int i = 0; i < N; i++) {
        X[i] = in();

        if (single && cnt[X[i]] > 0) {
            single = false;
        }
        cnt[X[i]] += 1;
    }

    sort(X, X + N);

    if (single) {
        printf("%d\n", N);
        for (int i = 0; i < N; i++) {
            printf("%d ", X[i]);
        }
        printf("\n");
    } else {
        int last = -1;

        vector<int> ans;

        for (int i = 0; i < N; i++) {
            if (cnt[X[i]] && X[i] > last) {
                cnt[X[i]] -= 1;
                ans.push_back(X[i]);
                last = X[i];
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            if (cnt[X[i]] && X[i] < last) {
                cnt[X[i]] -= 1;
                ans.push_back(X[i]);
                last = X[i];
            }
        }
        printf("%d\n", (int) ans.size());

        for (int i = 0; i < (int) ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }

    return 0;
}
