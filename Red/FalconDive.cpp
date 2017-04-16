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

const int MAXN = 1010;

int N, M;
string S;
string A[MAXN], B[MAXN];
char ANS[MAXN][MAXN];

int main(void) {
    while (cin >> N >> M >> S) {
        if (N == 0 && M == 0) {
            break;
        }
        char sd = S[1];
        vector<pair<int, int> > vpos;
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            
            for (int j = 0; j < M; j++) {
                if (A[i][j] == sd) {
                    vpos.push_back(make_pair(i, j));
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            cin >> B[i];
            
            for (int j = 0; j < M; j++) {
                if (B[i][j] == sd) {
                    ANS[i][j] = A[i][j];
                } else {
                    ANS[i][j] = B[i][j];
                }
            }
        }
        
        int pos = 0;               
                
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (B[i][j] == sd) {
                    int pi = i + (i - vpos[pos].first);
                    int pj = j + (j - vpos[pos].second);

                    if (pi >= 0 && pj >= 0 && pi < N && pj < M) {
                        ANS[pi][pj] = sd;
                    }
                    pos++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << ANS[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
