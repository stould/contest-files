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
 
int N, H;
pair<int, int> P[MAXN];
int dp[MAXN][MAXN];
 
int func(int pos, int t) {
    if (t == H || pos == N) {
        return 0;
    } else {
        int& ans = dp[pos][t];
 
        if (ans == -1) {
            ans = func(pos + 1, t);
			
            if (P[pos].second >= t) {
                chmax(ans, P[pos].first + func(pos + 1, t + 1));
            }
        }
 
        return ans;
    }
}
 
int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    for ( ; cin >> N >> H; ) {
        int sum = 0;
		
        for (int i = 0; i < N; i++) {           
            cin >> P[i].first >> P[i].second;
            sum += P[i].first;
        }
 
        sort(P, P + N,
             [](const pair<int, int> a, const pair<int, int> b) -> bool {
                 return a.second < b.second;
             });
 
        memset(dp, -1, sizeof(dp));
         
        cout << sum - func(0, 0) << "\n";
    }
    return 0;
}
