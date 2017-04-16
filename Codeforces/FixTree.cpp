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

const int MAXN = 200005;

int N;
int A[MAXN];
vector<int> G[MAXN];
int vis[MAXN];
set<pair<int, int> > rev;
int rt = -1;

void dfs(int node, int pr) {
    vis[node] = 1;

    for (int i = 0; i < (int) G[node].size(); i++) {
        int next = G[node][i];

        if (next == pr) continue;
        
        if (vis[next]) {
            if (rt == -1) {
                rt = min(node, next);
            }
            rev.insert(make_pair(min(node, next), max(node, next)));
        } else {
            dfs(next, node);
        }
    }
}

int main(void) {
    cin >> N;

    int ans = 0;

    int cnt = 0;
    
    map<int, int> cnt_root;
    set<int> seen_root;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];

        if (A[i] == i) {
            seen_root.insert(i);
        }
        cnt_root[A[i]] += 1;
    }

    for (set<int>::iterator it = seen_root.begin(); it != seen_root.end(); it++) {
        if (cnt_root[*it] > cnt) {
            cnt = cnt_root[*it];
            rt = *it;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] == i) {
            if (i != rt) {
                ans += 1;
                A[i] = rt;
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (A[i] == i) continue;
        G[A[i]].push_back(i);
        G[i].push_back(A[i]);
    }
    
    dfs(rt, -1);
    
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }

    ans += (int) rev.size();

    for (auto& it: rev) {
        A[it.first] = rt;
    }
    
    cout << ans << "\n";
    
    for (int i = 1; i <= N; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
