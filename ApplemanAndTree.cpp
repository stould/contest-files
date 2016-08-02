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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N;
vector<int> tree[MAXN];
Int dp[MAXN][2];
int cnt[MAXN];

Int func(int pos, int prev, int black) {
    if (black > 1) {
        return 0;
    } else if (tree[pos].size() == 1 && prev != -1) {
        return black == 1;
    } else {
        Int& ans = dp[pos][black];

        if (ans == -1) {
            ans = 0;
            
            for (int i = 0; i < (int) tree[pos].size(); i++) {
                int next = tree[pos][i];

                if (next == prev) continue;

                ans += func(next, pos, black + cnt[next]);
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int p;
        cin >> p;
        
        tree[i + 1].push_back(p);
        tree[p].push_back(i + 1);
    }

    for (int i = 0; i < N; i++) {
        cin >> cnt[i];
    }

    memset(dp, -1, sizeof dp);

    Int ans = func(0, -1, cnt[0]);

    cout << ans << endl;
    
    return 0;
}
