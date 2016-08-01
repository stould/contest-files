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

int N, M, K;
int A[10];
vector<int> NI, MI;
bool fine;
bool vis[110][110];

int fillRect(int bi, int bj, int li, int lj, bool kind) {
    int ans = 0;

    for (int i = bi; i < bi + li; i++) {
        for (int j = bj; j < bj + lj; j++) {
            if (vis[i][j] != kind) {
                ans += 1;
            }
            vis[i][j] = kind;
        }
    }
    
    return ans;
}

bool match(int bi, int bj, int li, int lj) {
    for (int i = bi; i < bi + li; i++) {
        if (i >= N) return false;
        for (int j = bj; j < bj + lj; j++) {
            if (j >= M) return false;
            
            if (vis[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

void dfs(int mask, int used, int avail, int r, int c) {
    //cout << r << " " << c << " " << __builtin_popcount(mask) << endl;
    //cout << used << endl;
    //cout << r << " " << c << " " << __builtin_popcount(mask) << endl;
    //for (int j = 0; j < N; j++) {
    //    for (int k = 0; k < M; k++) {
    //      cout << vis[j][k];
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    if (fine) return;
    if (used == N * M) {
        fine = true;
        return;
    } else if (avail < N * M - used) {
        return;
    } else if (__builtin_popcount(mask) == K) {
        return;
    } else {
        for (int i = 0; !fine && i < K; i++) {
            if (mask & (1 << i)) continue;

            //cout << "Try " << NI[i] << " " << MI[i] << endl;
            
            if (match(r, c, NI[i], MI[i])) {
                //cout << "In " << NI[i] << " " << MI[i] << endl;
                fillRect(r, c, NI[i], MI[i], true);
                bool found = false;
                int nj = N, nk = M;
                
                for (int j = 0; !found && j < N; j++) {
                    for (int k = 0; !found && k < M; k++) {
                        if (vis[j][k] == 0) {
                            nj = j;
                            nk = k;
                            found = true;
                        }
                    }
                }
                dfs(mask | (1 << i), used + NI[i] * MI[i], avail - NI[i] * MI[i], nj, nk);
                fillRect(r, c, NI[i], MI[i], false);                                            
            }

            //            cout << "Try " << MI[i] << " " << NI[i] << endl;
            if (match(r, c, MI[i], NI[i])) {
                //  cout << "In " << MI[i] << " " << NI[i] << endl;
                fillRect(r, c, MI[i], NI[i], true);
                bool found = false;
                int nj = N, nk = M;
                    
                for (int j = 0; !found && j < N; j++) {
                    for (int k = 0; !found && k < M; k++) {
                        if (vis[j][k] == 0) {
                            nj = j;
                            nk = k;
                            found = true;
                        }
                    }
                }
                dfs(mask | (1 << i), used + MI[i] * NI[i], avail - MI[i] * NI[i], nj, nk);
                fillRect(r, c, MI[i], NI[i], false);                                            
            }        
        }
    }
}

int main(void) {
    cin >> N >> M >> K;

    int avail = 0;
    
    for (int i = 0; i < K; i++) {
        int pi, pj;
        
        cin >> A[i] >> pi >> pj;
        
        for (int j = 0; j < A[i]; j++) {
            NI.push_back(pi);
            MI.push_back(pj);

            avail += pi * pj;
        }
    }

    K = (int) NI.size();

    fine = false;
    
    dfs(0, 0, avail, 0, 0);

    if (fine) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
