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

class DevuAndPlantingTrees {
public:
    int maximumTreesDevuCanGrow(vector <string>);
};

int N;
int dp[60][5];
vector<string> S;

int func(int pos, int bef) {
    if (pos == N) {
        return 0;
    } else {
        int& ans = dp[pos][bef];
		
        if (ans == -1) {
            bool here = (S[0][pos] == '*' || S[1][pos] == '*');
            bool next = false;
			
            if (pos + 1 < N) {
                next = (S[0][pos + 1] == '*' || S[1][pos + 1] == '*');
            }
			
            ans = (here ? 1 : 0) + func(pos + 1, here);
			
            if (!bef && !here && !next) {
                ans = max(ans, 1 + func(pos + 1, true));
            }
        }
		
        return ans;
    }
}

int DevuAndPlantingTrees::maximumTreesDevuCanGrow(vector <string> garden) {
    S = garden;
    N = (int) S[0].size();
	
    memset(dp, -1, sizeof(dp));
	
    return func(0, 0);	
}

//Powered by [KawigiEdit] 2.0!
