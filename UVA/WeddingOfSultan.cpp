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

const int MAXN = 200;

int T, N;
int test = 1;

int cnt[MAXN];

char str[MAXN];

int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        scanf("%s", str);

        N = strlen(str);

        memset(cnt, 0, sizeof(cnt));

        stack<int> s;
        s.push(str[0]);

        for (i = 1; i < N; i++) {
            if (!cnt[str[i] - 'A']) {
                cnt[str[i] - 'A'] += 1;
            }
            if (s.top() == str[i]) {
                s.pop();

                if (!s.empty()) cnt[s.top() - 'A'] += 1;
            } else {
                s.push(str[i]);
            }
        }

        printf("Case %d\n", test++);

        for (i = 0; i < 26; i++) if (cnt[i] > 0) {
            printf("%c = %d\n", 'A' + i, cnt[i]);
        }
    }

    return 0;
}
