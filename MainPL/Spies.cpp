#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <utility>
#include <functional>
 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
using namespace std;

int N, M;
 
namespace MF {
     const int MAXN = 1005;
 
     int nodes = MAXN, src, dest;
     int dist[MAXN], q[MAXN], work[MAXN];
 
     struct edge {
      int from;
         int to, rev;
         int f, cap;
     };
 
     vector<edge> g[MAXN];
 
     // Adds bidirectional edge
     void addEdge(int s, int t, int cap) {
       edge a = {s, t, g[t].size(), 0, cap};
       edge b = {t, s, g[s].size(), 0, cap};
       g[s].push_back(a);
       g[t].push_back(b);
     }
 
     bool dinic_bfs() {
         fill(dist, dist + nodes, -1);
         dist[src] = 0;
         int qt = 0;
         q[qt++] = src;
         for (int qh = 0; qh < qt; qh++) {
             int u = q[qh];
             for (int j = 0; j < (int) g[u].size(); j++) {
                 edge &e = g[u][j];
                 int v = e.to;
                 if (dist[v] < 0 && e.f < e.cap) {
                     dist[v] = dist[u] + 1;
                     q[qt++] = v;
                 }
             }
         }
         return dist[dest] >= 0;
     }
 
     int dinic_dfs(int u, int f) {
         if (u == dest)
             return f;
         for (int &i = work[u]; i < (int) g[u].size(); i++) {
             edge &e = g[u][i];
             if (e.cap <= e.f) continue;
             int v = e.to;
             if (dist[v] == dist[u] + 1) {
                 int df = dinic_dfs(v, min(f, e.cap - e.f));
                 if (df > 0) {
                     e.f += df;
                     g[v][e.rev].f -= df;
                  return df;
                }
             }
         }
         return 0;
     }
 
     int maxFlow(int _src, int _dest) {
         src = _src;
         dest = _dest;
         int result = 0;
         while (dinic_bfs()) {
             fill(work, work + nodes, 0);
             while (int delta = dinic_dfs(src, INT_MAX)) {
                 result += delta;
             }
         }
         return result;
     }
 };
 
 int a, b;
 
 int main(void) {
   cin >> N >> M;
 
   for (int i = 0; i < M; i++) {
     cin >> a >> b;
     MF::addEdge(a, b, 1);
   }

   int as = MF::maxFlow(1, N);

   int Q, curr;
   cin >> Q;

   vector<int> ans;
   
   for (int i = 0; i < Q; i++) {
     cin >> curr;
	 int check = (int) ceil(curr / (double) as);

	 if (check <= 0) {
		 ans.clear();
		 break;
	 } else {
		 ans.push_back(check);
	 }
   }

   if (ans.empty()) {
	   for (int i = 0; i < 63; i++) {
		   puts("zelazko");
	   }
   } else {
	   for (int i = 0; i < (int) ans.size(); i++) {
		   printf("%d\n", ans[i]);
	   }
   }
 
   return 0;
 } 
