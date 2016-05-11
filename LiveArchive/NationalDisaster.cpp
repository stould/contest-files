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

const int MAXN = 205;

int T;
int N;
Int X[MAXN], Y[MAXN];
bool P[MAXN][MAXN];
vector<Int> SV, SM;

Int dist(int a, int b) {
    return (X[a] - X[b]) * (X[a] - X[b]) + (Y[a] - Y[b]) * (Y[a] - Y[b]);
}

void create() {
    srand(time(NULL));
    int t = 20;

    cout << t << endl;
        
    for ( ; t--; ) {
        int n = 200;
        
        cout << n << "\n";
        
        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << n - i << " ";
        }
        cout << endl;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    cout << 1 << " ";
                } else {
                    cout << rand() % 2 << " ";
                }
            }
            cout << endl;
        }
    }
}

int main(void) {
    //create();
    //return 0;
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> T;

    for (int t = 1; t <= T; t++) {
        SV.clear();
        SM.clear();
        
        cin >> N;

        set<Int> all;

        for (int i = 0; i < N; i++) {
            cin >> X[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> Y[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> P[i][j];

                Int dst = dist(i, j);
                
                all.insert(dst);
                
                if (P[i][j]) {
                     SV.push_back(dst);
                } else {
                    SM.push_back(dst);
                }
            }
        }

        sort(SV.begin(), SV.end());
        sort(SM.begin(), SM.end());

        int best_lie = 100000;
        int best_dist = -1;

        for (set<Int>::iterator it = all.begin(); it != all.end(); it++) {
            Int curr = *it;

            int lie = 0;
            
            lie += (lower_bound(SM.begin(), SM.end(), curr + 1) - SM.begin());
            lie += (SV.end() - lower_bound(SV.begin(), SV.end(), curr + 1));
            
            //cout << all[i] << " " << lie << "\n";

            if (best_lie > lie || (best_lie == lie && best_dist > curr)) {
                best_lie = lie;
                best_dist = curr;
            }
        }

        cout << "Case #" << t << ": " << best_dist << " " << best_lie << "\n";
    }
    
    return 0;
}
