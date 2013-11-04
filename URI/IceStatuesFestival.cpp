#include <bits/stdc++.h>

using namespace std;

int i, j, x;
int n, m, c[30], dp[1000010], dist[1000010];

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    fastRead_int(x);
    for( ; x-->0; ) {
        fastRead_int(n);
        fastRead_int(m);

        for(i = 0; i < n; i++) {
            fastRead_int(c[i]);
        }
        for (i = 0; i <= m; i++) {
            dist[i] = INT_MAX / 5;
        }

        queue<int> q; q.push(0); dist[0] = 0;

        for ( ; !q.empty(); ) {
            int curr = q.front(); q.pop();

            if (curr > m) continue;

            if (curr == m) {
                printf("%d\n", dist[m]);
                break;
            }

            for (i = n - 1; i >= 0; i--) {
                q.push(curr + c[i]);
                dist[curr + c[i]] = min(dist[curr + c[i]], dist[curr] + 1);
            }
        }
    }
    return 0;
}
