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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N, M;
vector<int> G[MAXN];
int deg[MAXN];
bool ask[MAXN];
int P[MAXN];
vector<int> ans;

bool dfs(int node, int prev) {
    int cr = true;

    if (ask[node]) {
        prev = node;
        ans.push_back(node);        
    }

    for (int i = 0; i < (int) G[node].size(); i++) {
        int u = G[node][i];        
        
        if (u != prev) {
            if (!dfs(u, node)) {
                cr = false;
            }
        }
    }
    return cr;
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
        
        deg[B] = 1;
    }

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        ask[P[i]] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) {
            int cr = dfs(i, -1);
            
            if (!cr) {
                ans.clear();
                break;
            }
        }
    }

    if (!ans.empty()) {
        cout << ans.size() << "\n";
        
        for (int i = 0; i < (int) ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
