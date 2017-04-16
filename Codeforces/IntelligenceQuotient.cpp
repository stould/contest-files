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


const int MAXN = 440;
const int SET_SIZE = 400;

int N, M, K;
bitset<SET_SIZE> stA[MAXN], stB[MAXN];
Int P[MAXN], Q[MAXN];
Int dp[MAXN][MAXN];

Int funcA(int pos, int base) {
    if (pos == N) {
        Int ans = 0;

        for (int i = 0; i < M; i++) {
            if (stA[base].test(i)) {
                ans += Q[i];
            }
        }
        
        return ans;
    } else {        
        if (dp[pos][base] == -1) {
            dp[pos][base] = funcA(pos + 1, base);

            if (stA[pos] == stA[base]) {
                dp[pos][base] = max(dp[pos][base], P[pos] + funcA(pos + 1, base));
            }
        }
        
        return dp[pos][base];
    }
}

Int funcB(int pos, int base) {
    if (pos == M) {
        Int ans = 0;

        for (int i = 0; i < N; i++) {
            if (stB[base].test(i)) {
                ans += P[i];
            }
        }
        
        return ans;
    } else {        
        if (dp[pos][base] == -1) {
            dp[pos][base] = funcB(pos + 1, base);

            if (stB[pos] == stB[base]) {
                dp[pos][base] = max(dp[pos][base], Q[pos] + funcB(pos + 1, base));
            }
        }
        
        return dp[pos][base];
    }
}

int main(void) {
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int A, B;
        
        cin >> A >> B;

        A -= 1;
        B -= 1;

        stA[A].set(B);
        stB[B].set(A);
    }

    Int ia = 0;
    Int ib = 0;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        ia += P[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> Q[i];
        ib += Q[i];
    }

    Int ansA = 0;
    Int ansB = 0;
    
    int idA = -1;
    int idB = -1;
    
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < N; i++) {
        if (ansA < funcA(0, i)) {
            ansA = funcA(0, i);
            idA = i;
        }
    }

    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < M; i++) {
        if (ansB < funcB(0, i)) {
            ansB = funcB(0, i);
            idB = i;
        }
    }

    cout << max(ia, max(ib, max(ansA, ansB))) << endl;
    
    if (max(ia, ib) >= max(ansA, ansB)) {
        if (ia >= ib) {
            cout << N << endl;

            for (int i = 0; i < N; i++) {
                cout << i + 1 << " ";
            }
            cout << endl;

            cout << "0" << endl;
        } else {
            cout << "0" << endl;
            
            cout << M << endl;

            for (int i = 0; i < M; i++) {
                cout << i + 1 << " ";
            }
            cout << endl;
        }
    } else {
        if (ansA >= ansB) {
            int cnt = 0;
            
            for (int i = 0; i < N; i++) {
                if (stA[i] == stA[idA]) {
                    cnt += 1;
                }
            }
            
            cout << cnt << endl;
            
            for (int i = 0; i < N; i++) {
                if (stA[i] == stA[idA]) {
                    cout << i + 1 << " ";
                }
            }
            
            cout << endl << stA[idA].count() << endl;
            
            for (int i = 0; i < M; i++) {
                if (stA[idA].test(i)) {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
        } else {
            int cnt = 0;
            
            for (int i = 0; i < M; i++) {
                if (stB[i] == stB[idB]) {
                    cnt += 1;
                }
            }
            
            cout << cnt << endl;
            
            for (int i = 0; i < M; i++) {
                if (stB[i] == stB[idB]) {
                    cout << i + 1 << " ";
                }
            }
            
            cout << endl << stB[idB].count() << endl;
            
            for (int i = 0; i < M; i++) {
                if (stB[idB].test(i)) {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;    
}
