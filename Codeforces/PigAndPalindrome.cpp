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

const int MAXN = 510;
const Int MOD = 1000000007LL;

int N, M;
string S[MAXN];
Int UC[MAXN][MAXN];
Int LC[MAXN][MAXN];

int dxU[2] = {0, 1};
int dyU[2] = {1, 0};
int dxL[2] = {0, -1};
int dyL[2] = {-1, 0};

int dxALL[4] = {-1, 1, 0, 0};
int dyALL[4] = {0, 0, -1, 1};

void fixMod(Int& arg) {
    arg = ((arg % MOD) + MOD) % MOD;
}

bool in(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

void build() {
    queue<pair<int, pair<pair<int, int>, pair<int, int> > > > q;
    if (S[0][0] == S[N - 1][M - 1]) {
        UC[0][0] = 1;
        LC[N - 1][M - 1] = 1;
        q.push(make_pair(1, make_pair(make_pair(0, 0), make_pair(N - 1, M - 1))));
    }

    while (!q.empty()) {
        int len = q.front().first;
        int pi = q.front().second.first.first;
        int pj = q.front().second.first.second;
        int qi = q.front().second.second.first;
        int qj = q.front().second.second.second;
        q.pop();

        if (len + 1 > (N + M - 1) / 2) continue;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int ai = pi + dxU[i];
                int aj = pj + dyU[i];
                int bi = qi + dxL[j];
                int bj = qj + dyL[j];

                if (in(ai, aj) && in(bi, bj) && S[ai][aj] == S[bi][bj]) {
                    UC[ai][aj] += UC[pi][pj];
                    LC[bi][bj] += LC[qi][qj];

                    fixMod(UC[ai][aj]);
                    fixMod(LC[bi][bj]);

                    q.push(make_pair(len + 1, make_pair(make_pair(ai, aj), make_pair(bi, bj))));
                }
            }
        }
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    
    if (N == 1 && M == 1) {
        cout << "1\n";
    } else {    
        build();

        Int ans = 0LL;
        
        if ((N + M - 1) % 2 == 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    //cerr << "hi\n";
                    for (int k = 0; k < 2; k++) {
                        int pi = i + dxU[k];
                        int pj = j + dyU[k];
                        
                        if (in(pi, pj)) {
                            cout << i << " " << j << " = " << pi << " " << pj << " => " << UC[i][j] << " " << LC[pi][pj] <<" \n";
                            ans += min(UC[i][j], LC[pi][pj]);
                            fixMod(ans);
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    for (int k = 0; k < 4; k++) {
                        int pi = i + dxALL[k];
                        int pj = j + dyALL[k];
                        
                        if (in(pi, pj)) {
                            for (int l = 0; l < 4; l++) {
                                if (k == l) continue;
                                    
                                int qi = i + dxALL[l];
                                int qj = j + dyALL[l];

                                if (in(qi, qj)) {
                                    ans += min(UC[pi][pj], LC[qi][qj]);
                                    fixMod(ans);
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
