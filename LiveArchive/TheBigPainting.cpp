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

const int MAXN = 2020;

const uInt BASE = 7883ULL;
const uInt C_BASE = 4549ULL;

int N, M, A, B;
string S[2][MAXN];
uInt hsh[2][MAXN][MAXN];
uInt pwd[MAXN];
uInt cmp[MAXN];

void build(int id, int row) {
    hsh[id][row][0] = 0ULL;
    
    for (int i = 1; i <= (int) S[id][row].size(); i++) {
        hsh[id][row][i] = hsh[id][row][i - 1] * BASE + (S[id][row][i - 1]);
    }
}

uInt getHash(int id, int row, int l, int r) {
    return hsh[id][row][r] - hsh[id][row][l] * pwd[r - l] + cmp[r - l];
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    pwd[0] = 1ULL;
    cmp[0] = 1ULL;

    for (int i = 1; i < MAXN; i++) {
        pwd[i] = pwd[i - 1] * BASE;
        cmp[i] = cmp[i - 1] * C_BASE;
    }

    while (cin >> N >> M >> A >> B) {
        for (int i = 0; i < N; i++) {
            cin >> S[0][i];
            build(0, i);
        }
        for (int i = 0; i < A; i++) {
            cin >> S[1][i];
            build(1, i);
        }
        
        int ans = 0;

        for (int i = 0; i + N <= A; i++) {
            for (int j = 0; j + M <= B; j++) {
                int len = 0;
                int k = i;       
                
                while (len < N && getHash(0, len, 0, M) == getHash(1, k, j, j + M)) {
                    len += 1;
                    k += 1;
                }
                
                if (len >= N) {                    
                    ans += 1;
                }
            }
        }

        cout << ans << "\n";        
    }
    return 0;
}
