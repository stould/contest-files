#include <bits/stdc++.h>

using namespace std;

const int MAXN = 455;

int N, M;
int V[MAXN];
int BS[MAXN][MAXN];
vector<int> G[MAXN];

int dfs(int node, set<int> used) {
    if (used.size() >= 4) {
        return 0;
    } else {
        int ans = 0;

        for (int i = 0; i < (int) G[node].size(); i++) {
            int next = G[node][i];
      
            if (used.count(next)) continue;
      
            bool ok = true;
      
            for (auto it : used) {
                int other = it;
	
                if (!BS[next][other]) {
                    ok = false;
                }
            }
      
            if (ok) {
                set<int> other_set = used;
                other_set.insert(next);
	
                ans = max(ans, V[next] + dfs(next, other_set));
            }
        }        
        return ans;
    }
}

int main(void) {
    while (cin >> N >> M) {
        for (int i = 0; i < N; i++) {
            G[i].clear();
      
            for (int j = 0; j < N; j++) {
                BS[i][j] = 0;
            }

            cin >> V[i];
        }
    
        for (int i = 0; i < M; i++) {
            int A, B;
      
            cin >> A >> B;

            BS[A - 1][B - 1] = BS[B - 1][A - 1] = 1;

            G[A - 1].push_back(B - 1);
            G[B - 1].push_back(A - 1);
        }

        int ans = 0;
    
        for (int i = 0; i < N; i++) {
            set<int> st;
            st.insert(i);
            ans = max(ans, V[i] + dfs(i, st));
        }

        cout << ans << "\n";
    }
    return 0;
}
