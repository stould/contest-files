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

const int MAXN = 505;

int N;
Int P[MAXN][MAXN];
Int R[MAXN], C[MAXN];
Int D1, D2;

int main(void) {
    cin >> N;

    if (N == 1) {
        cout << "1\n";
        return 0;
    }

    Int best = 0;
    Int sm = LLONG_MAX;
    int pi = 0;
    int pj = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> P[i][j];

            if (P[i][j] == 0) {
                pi = i;
                pj = j;
            }
            
            R[i] += P[i][j];
            C[j] += P[i][j];
        }

        D1 += P[i][i];
        D2 += P[i][N - i - 1];
    }
    
    best = max(best, D1);
    best = max(best, D2);
    
    sm = min(sm, D1);
    sm = min(sm, D2);      

    for (int i = 0; i < N; i++) {
        best = max(best, R[i]);
        best = max(best, C[i]);

        sm = min(sm, R[i]);
        sm = min(sm, C[i]);
    }
    
    P[pi][pj] = best - sm;

    set<Int> st;
    
    D1 = D2 = 0;
    memset(R, 0, sizeof(R));
    memset(C, 0, sizeof(C));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            R[i] += P[i][j];
            C[j] += P[i][j];
        }
        D1 += P[i][i];
        D2 += P[i][N - i - 1];
    }

    for (int i = 0; i < N; i++) {
        st.insert(R[i]);
        st.insert(C[i]);
    }

    st.insert(D1);
    st.insert(D2);

    if (st.size() == 1 && P[pi][pj] > 0) {
        cout << P[pi][pj] << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
