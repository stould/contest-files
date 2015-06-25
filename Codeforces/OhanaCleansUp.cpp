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


const int MAXN = 110;

int N;
string S[MAXN];
vector<int> row[MAXN];

int main(void) {
    cin >> N;
    
    
    for (int i = 0; i < N; i++) {
        cin >> S[i];

        for (int j = 0; j < N; j++) {
            if (S[i][j] == '1') {
                row[i].push_back(j);
            }
        }       
    }

    int best = 0;
    
    for (int i = 0; i < N; i++) {
        string ref = S[i];
        int curr = 1;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                bool ok = true;
                for (int k = 0; k < N; k++) {
                    if (ref[k] != S[j][k]) {
                        ok = false;
                    }
                }
                if (ok) curr += 1;
            }
        }
        best = max(best, curr);
    }

    cout << best << "\n";
    
    return 0;
}
