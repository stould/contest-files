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

const int MAXN = 100007;

int T, M;
int N;

pair<int, int> p[MAXN];
bool used[MAXN];

bool comp(const pair<int, int> a, const pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main(void) {
    freopen("i.in", "r", stdin);
    T = in();

    int i;
    int A, B;

    for ( ; T--; ) {
        M = in();

        N = 0;

        for ( ; scanf("%d%d", &A, &B) == 2 && (A + B != 0); ) {
            if (B < 0) continue;
            p[N] = make_pair(A, B);
            used[N] = false;
            N++;
        }

        sort(p, p + N, comp);

        int cnt = 0;
        int l = 0;
        int r = 0;

        bool ok = true;

        for (i = 0; i < N && r < M; ) {
            int pos = i;
            bool done = false;
            while (i < N && p[i].first <= l) {
                if (p[i].second) {
                    pos = i;
                    r = p[i].second;
                }
                i++;
                done = true;
            }
            //printf("%d %d\n", p[pos].first, p[pos].second);
            if (!done) {
                ok = false;
                break;
            }
            cnt += 1;
            used[pos] = 1;
        }

        if (!ok) {
            puts("0");
        } else {
            printf("%d\n", cnt);

            for (i = 0; i < N; i++) if (used[i]) {
                printf("%d %d\n", p[i].first, p[i].second);
            }
        }
        printf("\n");
    }

    return 0;
}
