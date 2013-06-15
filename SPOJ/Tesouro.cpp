#include <stdio.h>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000000;
const int MAXV = 1010;

struct Edge {
    int d, w;

    Edge() { }

    Edge(int d, int w) :
        d(d), w(w) {
    }
};

int dist[MAXV], ordenacaoTop[MAXV], indeg[MAXV], degree[MAXV];
vector<Edge> adj[MAXV];

void connect(int u, int v, int w) {
    degree[u]++;
    indeg[v]++;
    adj[u].push_back(Edge(v, w));
}

void topsort(int N) {
    queue<int> q;
    int atual, proximo, j = 0;

    for(int i = 0; i < N; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        atual = q.front();
        q.pop();
        ordenacaoTop[j++] = atual;
            for(int i = 0; i < degree[atual]; i++) {
                proximo = adj[atual][i].d;
                indeg[proximo]--;
                    if (indeg[proximo] == 0) {
                        q.push(proximo);
                    }
                }
        }
}

int disjktra(int disjktra, int to, int N) {
    topsort(N);
    for(int v = 0; v < N; v++) {
       dist[v] = -INF;
    }
    dist[disjktra] = 0;
    for (int i = 0, v = ordenacaoTop[i]; i < N; v = ordenacaoTop[i++]) {
        for(int j = 0; j < degree[v]; j++) {
            Edge p = adj[v][j];
            if(dist[p.d] < dist[v] + p.w) {
                dist[p.d] = dist[v] + p.w;
            }
        }
    }
    return dist[to];
}

int main() {
    freopen("i.in", "r", stdin);
    int N, Q, P, v;

    while (1) {
        scanf("%d", &N);

        if (N == 0) break;

        for(int u = 0; u <= N + 1; u++) {
            indeg[u] = 0, degree[u] = 0;
                adj[u].clear();
            }

        for(int u = 1; u <= N; u++) {
            scanf("%d %d", &Q, &P);

            connect(0, u, 0);
            connect(u, N + 1, Q);

            for(int j = 0; j < P; j++) {
                scanf("%d", &v);
                connect(u, v, Q);
            }
        }
        printf("%d\n", disjktra(0, N + 1, N + 2));
        for(int i = 1; i <= N; i++) {
            printf("%d ", ordenacaoTop[i]);
        }
        printf("\n");
    }
    return 0;
}
