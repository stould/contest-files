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

const int MAXN = 2020;

int N;
int MT[MAXN][MAXN];
vector<int> G[MAXN];
set<vector<int> > buff;
bool vis[MAXN];

void dfs(int x, int start, int depth, vector<int> st) {
  if (st.size() == 5) {
    if (st.back() == start) {
      buff.insert(st);

    }
  } else {
    for (int i = 0; i < (int) G[x].size(); i++) {
      int u = G[x][i];
      
      if (find(st.begin(), st.end(), i) == st.end() || (st.size() == 4 && i == start)) {
        vector<int> ot = st;
        ot.push_back(i);
        dfs(u, start, depth + 1, ot);
      }        
    }
  }
}


int main(void) {
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> MT[i][j];

      if (MT[i][j]) {
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }
  }


  for (int i = 0; i < N; i++) {
    vector<int> base;
    base.push_back(i);
    dfs(i, i, 0, base);
  }

  cout << buff.size() / (4 * N) - (N / 2) - 1 << "\n";
  return 0;
}
