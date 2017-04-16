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

int T, N;
int P[30][30];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        set<int> row[N];
        set<int> col[N];
        
        bool ok = true;

        set<int> cnt[N];
        int srow = 0;

        for (int i = 0; i < N; i++) {
            row[i].clear();
            col[i].clear();
            cnt[i].clear();
        }
        
        for (int i = 0; i < N; i++) {
            if (i > 0 && i % (int) sqrt(N) == 0) srow += sqrt(N);
            
            int st = srow;
            for (int j = 0; j < N; j++) {
                if (j > 0 && j % (int) sqrt(N) == 0) {
                    st += 1;
                }

                cin >> P[i][j];

                row[i].insert(P[i][j]);
                col[j].insert(P[i][j]);
                cnt[st].insert(P[i][j]);
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (N != (int) cnt[i].size()) {
                ok = false;                
            }
            if (N != (int) row[i].size()) {
                ok = false;
            }
            if (N != (int) col[i].size()) {
                ok = false;
            }
        }

        if (ok) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
