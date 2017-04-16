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

int P[5][5];
int R[5], C[5];
int SR[5], SC[5];
int DP, DS;

int main(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> P[i][j];

            if (P[i][j] == 0) {
                R[i] = 1;
                C[j] = 1;
            }

            SR[i] += P[i][j];
            SC[j] += P[i][j];

            if (i == j) {
                DP += P[i][j];
            }
        }
    }

    DS += P[0][2] + P[1][1] + P[2][0];

    int all = max(DP, DS);

    for (int i = 0; i < 3; i++) {
        all = max(all, SR[i]);
        all = max(all, SC[i]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (P[i][j] == 0) {
                P[i][j] = max(all - SR[i], all - SC[j]);
                if (i == j) {
                    P[i][j] = max(P[i][j], all - DP);
                    P[i][j] = max(P[i][j], all - DS);
                }
                if ((i == 0 && j == 2) || (i == 2 && j == 0)) {
                    P[i][j] = max(P[i][j], all - DS);
                }
            }
            cout << P[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
