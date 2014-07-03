#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000010;
const int INF = INT_MAX / 4;

int i, j, x;
int n, m, c[30], dist[MAXN], q[MAXN];

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
    fastRead_int(x);

    for( ; x--> 0; ) {
        fastRead_int(n);
        fastRead_int(m);

        for(i = 0; i < n; i++) {
            fastRead_int(c[i]);
        }
		sort(c, c + n);

		for (i = 0; i <= m; i++) {
			dist[i] = INF;
		}


		int qF = 0, qE = 0;

		q[qE++] = 0;
        dist[0] = 0;

        for ( ; qF < qE; ) {
            int curr = q[qF++];
			
			if (curr == m) {
                printf("%d\n", dist[m]);
                break;
            }

            for (i = n - 1; i >= 0; i--) {
				if (curr + c[i] <= m) {
					if (dist[curr + c[i]] > dist[curr] + 1) {
						q[qE++] = curr + c[i];
						dist[curr + c[i]] = min(dist[curr + c[i]], dist[curr] + 1);
					}
				}
            }
        }
    }
    return 0;
}
