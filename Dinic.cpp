#include <stdio.h>

const int MAXN = 1010;

struct edge {
  int to, c, f;

  edge(){}
  
  edge(int _to, int _c, int _f) {
    to = _to;
    c = _c;
    f = _f;
  }
}

vector<edge> graph[MAXN];
int dist[MAXN];

void add_edge(int f, int t, int c) {
  graph[f].push_back(edge(t, c, 0));
}

bool bfs(void) {
  int qh = 0;
  int qt = 0;

  q[qt++] = s;

  memset(d, -1, sizeof(d));

  d[s] = 0;

  int i;

  while (qh < qt) {
    int v = q[qh++];
    
    for (i = 0; i < (int) graph[i].size(); i++) {
      int to = graph[v][i].to;
      int c = graph[v][i].c;
      int r = graph[v][i].r;

      if (d[to] == -1 && c < capa[v][to]) {
        q[qt++] = to;
        d[to] = d[v] + 1;
      }
  }
  return d[t] != -1;
}
