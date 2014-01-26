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

int N, M, Q;
map<string, int> sn;
map<string, int> sm;

string S;

string BN[110], BM[110];

bool match[110][110];

string buff[110];

vector<string> ans[110];

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> BN[i];
        sn[BN[i]] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        cin >> BM[i];
        sm[BM[i]] = i + 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> Q;

        for (int j = 0; j < Q; j++) {
            cin >> buff[j];

            for (int k = 0; k < j; k++) {
                int ida = -1;
                int idb = -1;

                if (sn[buff[j]] == 0) {
                    ida = sn[buff[k]];
                } else {
                    ida = sn[buff[j]];
                }
                if (sm[buff[j]] == 0) {
                    idb = sm[buff[k]];
                } else {
                    idb = sm[buff[j]];
                }
                if (ida <= 0 || idb <= 0) continue;
                match[ida-1][idb-1] = true;
             }
        }
    }

    bool possible = true;

    for (int i = 0; possible && i < N; i++) {
        int ac = accumulate(match[i], match[i] + N, 0);

        if (ac != N) {
            for (int j = 0; j < N; j++) {
                if (!match[i][j]) {
                    ans[i].push_back(BM[j]);
                }
            }
        } else {
            possible = false;
        }
    }

    if (!possible) {
        cout << "IMPOSSIVEL\n";
    } else {
        for (int i = 0; i < N; i++) {
            cout << BN[i] << ": ";
            for (int j = 0; j < (int) ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
