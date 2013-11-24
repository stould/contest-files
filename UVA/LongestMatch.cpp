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

const int MAXN = 1010;

int N, M;
int dp[MAXN][MAXN];
bool mark[MAXN][MAXN];

string A, B;

bool isletter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

vector<string> split(string s) {
    int i;

    for (i = 0; i < (int) s.size(); i++) {

        if (!isletter(s[i]) && !isdigit(s[i])) {
            s[i] = ' ';
        }
    }

    vector<string> ans;
    string buff;

    istringstream ss(s);

    for ( ; ss >> buff; ) {
        ans.push_back(buff);
    }

    return ans;
}

int main(void) {
    int test = 1;

    int i;
    int j;

    for ( ; getline(cin, A); ) {
        getline(cin, B);

        vector<string> va = split(A);
        vector<string> vb = split(B);

        N = (int) va.size();
        M = (int) vb.size();

        cout << setw(2) << setiosflags(ios::right) << test++ << ". ";

        if (N == 0 || M == 0) {
            cout << "Blank!\n";
        } else {

            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    if (va[i] == vb[j]) {
                        mark[i][j] = true;
                    } else {
                        mark[i][j] = false;
                    }
                    dp[i][j] = 0;
                }
            }

            for (i = N; i >= 0; i--) {
                for (j = M; j >= 0; j--) {
                    if (i == N || j == M) {
                        dp[i][j] = 0;
                    } else {
                        chmax(dp[i][j], dp[i + 1][j]);
                        chmax(dp[i][j], dp[i][j + 1]);

                        if (va[i] == vb[j]) {
                            chmax(dp[i][j], 1 + dp[i + 1][j + 1]);
                        }
                    }
                }
            }

            cout << "Length of longest match: " << dp[0][0] << "\n";
        }
    }
    return 0;
}
