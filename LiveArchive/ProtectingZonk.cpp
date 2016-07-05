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
typedef unsigned uint;

const int MAXN = 10005;
const int INF = INT_MAX / 3;

int N, C, D;
int U, V;
vector<int> tree[MAXN];
int dp[MAXN][5][5][5][5];

//
//pr = previous edge
//uc = pre-previous edge
//nx = next edge
//hs = 1 if node is obligated to use a sargeant bot

int func(int node, int prev, int pr, int uc, int nx, int hs) {
    if (tree[node].size() == 1 && prev != -1) {
        if (pr == 1) {
            return 0;
        } else if (pr == 0 && uc == 1) {
            return min(C, D);
        } else {
            return D;
        }
    } else {
        int& ans = dp[node][pr][uc][nx][hs];
		
        if (ans == -1) {
            ans = INF;
            
            if (hs) {
                ans = D;
                
                for (int i = 0; i < (int) tree[node].size(); i++) {
                    int u = tree[node][i];

                    ans += func(u, node, 1, 1, 1, 0);
                }             
            } else {            
                int use_d = D;
                
                for (int i = 0; i < (int) tree[node].size(); i++) {
                    int u = tree[node][i];
                    
                    use_d += func(u, node, 1, 1, 1);
                }

            }
            chmin(ans, use_d);

            if (uc) {
                
            }
        }
        
        return ans;
    }
}

int main(void) {
    for ( ; cin >> N >> C >> D; ) {
        if (N == 0 && C == 0 && D == 0) break;

        for (int i = 0; i < MAXN; i++) {
            tree[i].clear();
        }
		
        for (int i = 0; i < N - 1; i++) {
            cin >> U >> V;
			
            tree[U].push_back(V);
            tree[V].push_back(U);
        }
	
        int ans = INF;
        
        for (int i = 1; i <= N; i++) {
            if (tree[i].size() == 1) {
                memset(dp, -1, sizeof(dp));
                chmin(ans, func(i, -1, 1, 1, 0));
                cout << i << " " << func(i, -1, 1, 1, 0) <<endl;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
