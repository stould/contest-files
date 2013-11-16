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

int T;
int N;

char str[60][60];
string ans;

int vis[60];

bool func(string s) {
    int i;

    for (i = 0; i < (int) s.size(); i++) {
        if (s[i] != s[(int) s.size() - i - 1]) return false;
    }

    return true;
}

void dfs(int x, string curr) {
    cout << curr << "\n";
    if (x == N - 1) {
        if (func(curr)) {
            if (curr.size() > ans.size() || (curr.size() == ans.size() && curr < ans)) {
                ans = curr;
            }
        }
    } else {
        int i;

        vis[x] = 1;

        for (i = x + 1; i < N; i++) if (x != i) {
            if (!vis[i]) {
                vis[i] = 1;

                dfs(i, curr + str[x][i]);

                vis[i] = 0;
            }
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    T = in();

    int i;

    for ( ; T--; ) {
        N = in();

        for (i = 0; i < N; i++) {
            scanf("%s", str[i]);
        }

        memset(vis, 0, sizeof(vis));

        ans = "";
        dfs(0, "");

        if (ans == "") {
            puts("");
        } else {
            puts(ans.c_str());
        }
    }

    return 0;
}

