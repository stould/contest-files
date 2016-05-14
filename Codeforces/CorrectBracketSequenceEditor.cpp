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

const int MAXN = 500010;
const int INF = 1000010;
int N, M, P;
string S, O;
int E[MAXN];
int L[MAXN], R[MAXN];
int up[MAXN];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M >> P;

    cin >> S >> O;

    stack<int> s;
    
    for (int i = 0; i < N; i++) {
        L[i] = i - 1;
        R[i] = i + 1;
        
        if (S[i] == '(') {
            s.push(i);
        } else {
            int pos = s.top();
            s.pop();

            E[i] = pos;
            E[pos] = i;
        }
    }

    int pos = P - 1;
    
    for (int i = 0; i < M; i++) {
        if (O[i] == 'R') {
            pos = R[pos];
        } else if (O[i] == 'L') {
            pos = L[pos];
        } else {
            int l = min(pos, E[pos]);
            int r = max(pos, E[pos]);

            up[l] = -1;
            up[r] = 1;
            
            int pl = L[l];
            int pr = R[r];
            
            if (pl >= 0) {
                R[pl] = pr;
            }
            if (pr < N) {
                L[pr] = pl;
            }

            if (R[max(pos, E[pos])] < N) {
                pos = R[max(pos, E[pos])];
            } else {
                pos = L[min(pos, E[pos])] ;
            }
        }
    }
    
    string ans = "";
    bool on = true;
    
    for (int i = 0; i < N; i++) {
        cout << up[i] << " ";
        if (up[i] == -1) {
            on = false;
        } else if (up[i] == 1) {
            on = true;
        }
        if (on) {
            ans += S[i];
        }
    }
    cout << ans << "\n";
    
    return 0;
}
