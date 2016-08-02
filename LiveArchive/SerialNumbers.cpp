#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

const int MAXN = 110;
const int MAXD = 12;

int test;
int N, K, L, V;

Int dp[MAXD][MAXN][10][2][2];
int mark[MAXD][MAXN][10][2][2];
int state = 1;
string SN;

int T[MAXN], term[MAXN], sig[MAXN][MAXD], cnt;
string S[11];

void add(string& arg) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) arg[i] - '0';
        if (sig[x][c] == 0) {
            term[cnt] = 0;
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }
    term[x] = 1;
}


void aho (){
    queue <int> Q;
    for (int i = 0; i < MAXD; i++){
        int v = sig[0][i];

        if (v) {
            Q.push (v);
            T[v] = 0;
        }
    }
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < MAXD; i++){
            int x = sig[u][i];

            if (x == 0) {
                continue;
            }

            int v = T[u];

            while (sig[v][i] == 0 && v != 0) {
                v = T[v];
            }

            int y = sig[v][i];
            Q.push(x);
            T[x] = y;
            term[x] |= term[y];
        }
    }
}

string to_int(Int val) {
    string ans = "";

    if (val == 0) return "";

    while (val > 0) {
        char now = '0' + (val % 10);
        ans = now + ans;
        val /= 10;
    }

    return ans;
}

Int func(int pos, int trie_pos, int last, int pref, int non_zero) {
    if (pos == L) {
        return 1;
    } else {
        Int& ans = dp[pos][trie_pos][last][pref][non_zero];

        if (mark[pos][trie_pos][last][pref][non_zero] != state) {
            mark[pos][trie_pos][last][pref][non_zero] = state;
            ans = 0;

            for (int i = 0; i <= 9; i++) {
                if (pref && i > SN[pos] - '0') continue;

                int next_pos = trie_pos;

                while (next_pos != 0 && sig[next_pos][i] == 0) {
                    next_pos = T[next_pos];
                }

                next_pos = sig[next_pos][i];

                if (i == 0 && !non_zero) next_pos = trie_pos;
                if (term[next_pos]) continue;
                
                ans += func(pos + 1, next_pos, i, pref && SN[pos] - '0' <= i, non_zero || i > 0);
            }
        }

        return ans;

    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> test;

    for (int t = 0; t < test; t++) {
        cin >> K;

        memset(sig, 0, sizeof(sig));

        cnt = 1;

        for (int i = 0; i < K; i++) {
            cin >> S[i];
            add(S[i]);
        }

        aho();

        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> V;
            
            Int l = 1, h = 10000000000LL;
            Int ans = -1;

            while (l <= h) {
                Int m = (l + h) / 2;
                
                SN = to_int(m);
                L = (int) SN.size();
                //memset(dp, -1, sizeof(dp));

                state++;
                Int cnt = func(0, 0, 10, 1, 0) - 1;
                
                //cout << m << " " << cnt << endl;
                if (cnt == V) {
                    ans = m;
                }
                if (cnt >= V) {
                    ans = m;
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (i > 0) cout << " ";
            cout << ans;            
        }
        cout << "\n";
    }
    return 0;
}
