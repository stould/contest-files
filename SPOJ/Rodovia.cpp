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

const int MAXN = 10005;

int A, B, N;
vector<int> g[MAXN], tr_g[MAXN];
bool vis[MAXN];

vector<int> order;

void dfs1(int x) {
  vis[x] = 1;

  for (int i = 0; i < (int) g[x].size(); i++) {
    int u = g[x][i];

    if (!vis[u]) {
      dfs1(u);
    }
  }

  order.push_back(x);
}

void dfs2(int x) {
  vis[x] = 1;

  for (int i = 0; i < (int) tr_g[x].size(); i++) {
    int u = tr_g[x][i];

    if (!vis[u]) {
      dfs2(u);
    }
  }
}

int main(void) {
  for ( ; cin >> N; ) {
    order.clear();
    for (int i = 0; i <= N; i++) {
      g[i].clear();
      tr_g[i].clear();
      vis[i] = 0;
    }
    for (int i = 0; i < N; i++) {
      cin >> A >> B;
      g[A].push_back(B);
      tr_g[B].push_back(A);
    }
    
    for (int i = 1; i <= N; i++) {
      if (!vis[i]) {
	dfs1(i);
      }
    }

    memset(vis, 0, sizeof(vis));
    reverse(order.begin(), order.end());
    
    int c = 0;
    
    for (int i = 0; i < N; i++) {
      if (!vis[order[i]]) {
	dfs2(order[i]);
	c += 1;
      }
    }
    
    cout << (c == 1 ? "S" : "N") << endl;
  }
  return 0;
}
