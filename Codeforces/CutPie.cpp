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

const int MAXN = 32;

int T, N, M;
char S[MAXN][MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        for (int i = 3; i < 3 + N; i++) {
            for (int j = 3; j < 3 + M; j++) {
                cin >> S[i][j];
            }
        }
        bool found = false;

        for (int i = 3; i < 3 + N; i++) {
            for (int j = 3; j < 3 + M; j++) {
                if (S[i][j] == 'p' && S[i + 1][j] == 'i' && S[i + 2][j] == 'e') {
                    found = true;
                }
                if (S[i][j] == 'p' && S[i - 1][j] == 'i' && S[i - 2][j] == 'e') {
                    found = true;
                }
                if (S[i][j] == 'p' && S[i][j + 1] == 'i' && S[i][j + 2] == 'e') {
                    found = true;
                }
                if (S[i][j] == 'p' && S[i][j - 1] == 'i' && S[i][j - 2] == 'e') {
                    found = true;
                }
                if (S[i][j] == 'p' && S[i + 1][j + 1] == 'i' && S[i + 2][j + 2] == 'e') {
                    found = true;
                }
                if (S[i][j] == 'p' && S[i + 1][j - 1] == 'i' && S[i + 2][j - 2] == 'e') {
                    found = true;
                }
                if (S[i][j] == 'p' && S[i - 1][j + 1] == 'i' && S[i - 2][j + 2] == 'e') {
                    found = true;
                }
                if (S[i][j] == 'p' && S[i - 1][j - 1] == 'i' && S[i - 2][j - 2] == 'e') {
                    found = true;
                }
            }
        }
        if (found) {
            cout << "Cutie Pie!\n";
        } else {
            cout << "Sorry Man\n";
        }
    }
    return 0;
}
