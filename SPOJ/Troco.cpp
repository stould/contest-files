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

const int MAXN = 100005;
const int INF = INT_MAX / 3;

int N, K;
int X[1004];

bool dp[1003][100003];
bool memo[1003][100003];

bool func(int id, int K) {
    if (K < 0) {
        return false;
    } else if (id == N) {
        return (K == 0);
    } else {
        bool& ans = dp[id][K];
        
        if (!memo[id][K]) {
            memo[id][K] = true;
            
            ans |= (func(id + 1, K - X[id]) || func(id + 1, K));
        }
        
        return ans;
    }
}

int main(void) {
    cin >> K >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }    
    cout << (func(0, K) ? "S" : "N") << "\n";
    return 0;
}
