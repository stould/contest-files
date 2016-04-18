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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 55;

int T, N;
int P[MAXN][MAXN];
int A[MAXN][MAXN];
bool V[MAXN];
bool ok;

bool match_row(int row, int p) {
    for (int i = 0; i < row; i++) {
        if (A[row][i] != P[p][i]) return false;
    }
    return true;
}

bool match_col(int col, int p) {
    for (int i = 0; i < col; i++) {
        if (A[i][col] != P[p][i]) return false;
    }
    return true;
}

void rec(int pos) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    if (pos == N) {
        ok = true;
    } else {
        for (int i = 0; !V[i] && i < 2 * N - 1; i++) {
            for (int j = 0; !V[j] && j < 2 * N - 1; j++) {
                if (i != j && match_row(pos, i) && match_col(pos, j)) {
                    for (int k = pos; k < N; k++) {
                        A[pos][k] = P[i][k];
                        A[k][pos] = P[j][k];
                    }

                    V[i] = V[j] = true;
                    
                    rec(pos + 1);
                    
                    V[i] = V[j] = false;

                    for (int k = pos; k < N; k++) {
                        A[pos][k] = -1;
                        A[k][pos] = -1;
                    }
                }
            }
        }
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        set<vector<int> > cnt;

        for (int i = 0; i < 2 * N - 1; i++) {
            vector<int> buff;
            for (int j = 0; j < N; j++) {
                cin >> P[i][j];

                buff.push_back(P[i][j]);
            }

            cnt.insert(buff);
        }

        ok = false;

        for (int i = 0; !ok && i < 2 * N - 1; i++) {
            for (int j = i + 1; !ok && j < 2 * N - 1; j++) {
                if (P[i][0] == P[j][0]) {
                    memset(V, false, sizeof(V));
                    memset(A, -1, sizeof(A));

                    for (int k = 0; k < N; k++) {
                        A[0][k] = P[i][k];
                        A[k][0] = P[j][k];
                    }

                    rec(1);
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < N; i++) {
            vector<int> buff_r;
            vector<int> buff_c;

            for (int j = 0; j < N; j++) {
                buff_r.push_back(A[i][j]);
                buff_r.push_back(A[j][i]);
            }

            if (!cnt.count(buff_r)) {
                ans = buff_r;
                break;
            }

            if (!cnt.count(buff_c)) {
                ans = buff_c;
                break;
            }
        }

        cout << "Case #" << t << ": ";

        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        
        cout << endl;
    }
    return 0;
}
