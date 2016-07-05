#include <bits/stdc++.h>

using namespace std;

const int MAXN = 12;

int N, T;
int reach[MAXN][MAXN];
bool good[MAXN][MAXN];
string S[MAXN];
pair<int, int> dp[MAXN][MAXN][(1 << 17)];

int dx[9] = {0, -1, 1, 0, 0, -1, 1, -1, 1};
int dy[9] = {0, 0, 0, -1, 1, -1, 1, 1, -1};

pair<int, int> func(int r, int c, int mask) {
    if (r == 10) {
        return make_pair(__builtin_popcount(mask), 0);
    } else if (c == 10) {
        return func(r + 1, 0, mask);
    } else {
        pair<int, int>& ans = dp[r][c][mask];
       
        if (ans.first == -1) {
            ans = func(r, c + 1, mask);
           
            if (good[r][c]) {
                if ((mask | reach[r][c]) != mask) {
                    pair<int, int> next = func(r, c + 1, mask | (reach[r][c]));
                    next.second += 1;
                   
                    if (next.first > ans.first || (next.first == ans.first && next.second < ans.second)) {
                        ans = next;
                    }
                }
            }
        }
       
        return ans;
    }
}

int main() {
    cin >> T;
   
    N = 10;
   
    for ( ; T--; ) {
        map<pair<int, int>, int> mp;
        int id = 0;
       
        for (int i = 0; i < N; i++) {
            cin >> S[i];
                       
            for (int j = 0; j < N; j++) {
                if (S[i][j] == 'e') {
                    mp[make_pair(i, j)] = id++;
                }
                //clean   
                reach[i][j] = 0;                       
                good[i][j] = false;
               
                for (int k = 0; k <= (1 << 16); k++) {
                    dp[i][j][k] = make_pair(-1, 0);
                }
            }
        }
       
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bool ok = true;
               
                for (int k = 0; k < 9; k++) {
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                   
                    if (ii >= 0 && ii < N && jj >= 0 && jj < N) {
                        if (S[ii][jj] == 'g') {
                            ok = false;
                        } else if (S[ii][jj] == 'e') {
                            reach[i][j] |= (1 << mp[make_pair(ii, jj)]);
                        }
                    }
                }
                good[i][j] = ok;
            }
        }
        pair<int, int> ans = func(0, 0, 0);
       
        cout << ans.first << " " << ans.second << "\n";
       
    }
    return 0;
}
