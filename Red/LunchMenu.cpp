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

const int MAXN = 5050;

int L;
int N[5];
int P[5][MAXN];

int main(void) {
    while (cin >> L >> N[0] >> N[1] >> N[2] >> N[3]) {
        if (L == 0 && N[0] == 0 && N[1] == 0 && N[2] == 0 && N[3] == 0) {
            break;
        }
        vector<Int> vprod;
        
        for (int x = 0; x < 4; x++) {
            for (int i = 0; i < N[x]; i++) {
                cin >> P[x][i];
            }
        }

        for (int i = 0; i < N[2]; i++) {
            for (int j = 0; j < N[3]; j++) {
                vprod.push_back(P[2][i] + P[3][j]);
            }
        }

        sort(vprod.begin(), vprod.end());

        Int ans = 0;

        for (int i = 0; i < N[0]; i++) {
            for (int j = 0; j < N[1]; j++) {
                Int sum = P[0][i] + P[1][j];

                int l = 0, h = (int) vprod.size() - 1, m;
                int pos = -1;
                
                while (l <= h) {
                    m = (l + h) / 2;

                    if (sum + vprod[m] <= L) {
                        pos = m;
                        l = m + 1;
                    } else {
                        h = m - 1;
                    }
                }

                ans += pos + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
