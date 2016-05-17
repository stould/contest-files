#include <bits/stdc++.h>

using namespace std;

const int MAXN = 18;
int T, X, Y;
int dp[MAXN][MAXN];

int dx[4] = {-2, -2,  1, -1};
int dy[4] = { 1, -1, -2, -2};

bool in(int x, int y) {
    return x >= 1 && y >= 1 && x <= 15 && y <= 15;
}

bool can(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int aa = x + dx[i];
        int bb = y + dy[i];

        if (in(aa, bb)) {
            return true;
        }
    }
    return false;
}

int func(int a, int b) {
    if (!can(a, b)) {
        return 0;
    } else {
        int& ans = dp[a][b];
    
        if (ans == -1) {
            set<int> st;

            for (int i = 0; i < 4; i++) {
                int aa = a + dx[i];
                int bb = b + dy[i];

                if (in(aa, bb)) {
                    st.insert(func(aa, bb));
                }
            }
      
            ans = 0;

            for ( ; ; ) {
                if (!st.count(ans)) {
                    break;
                }
                ans += 1;
            }
        }

        return ans;
    }
}

int main() {
    cin >> T;

    memset(dp, -1, sizeof(dp));

    for (int t = 1; t <= T; t++) {
        cin >> X >> Y;

        if (func(X, Y) != 0) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    return 0;
}
