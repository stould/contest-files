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
typedef unsigned uint;

const int MAXN = 1010;

int N, M;
int G[MAXN], S[MAXN];
char bf;

int main(void) {    
    cin >> N >> M;
    
    bool ok = true;

    set<int> pos;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> bf;
            
            if (bf == 'G') {
                G[i] = j;
            } else if (bf == 'S') {
                S[i] = j;
            }
        }
        if (G[i] > S[i]) {
            ok = false;
        } else {
            pos.insert(G[i] - S[i]);
        }
    }
    if (!ok) {
        cout << "-1" << endl;
    } else {    
        cout << (int) pos.size() << endl;
    }
       
    return 0;
}
