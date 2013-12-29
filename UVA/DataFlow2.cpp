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

const int MAXN = 210;
const Int INF = 1001000010010LL;

int N, M;

Int cap[MAXN][MAXN];
Int res[MAXN][MAXN];
Int cst[MAXN][MAXN];

vector<int> graph[MAXN];

int A[5050];
int B[5050];

Int D, K;
Int C[5050];

Int dist[MAXN];
Int end_flow[MAXN];
int ancs[MAXN];

void add_edge(int f, int t, Int cost, Int flow) {
    cap[f][t] = flow;
    cst[f][t] = cost;

    graph[f].push_back(t);
}

struct MyLess {
    bool operator()(int a, int b) {
        return dist[a] > dist[b];
    }
};

bool augment_path(int s, int t) {
    priority_queue<int, vector<int>, MyLess> q;

    fill(dist, dist + N + 1, INF);
    fill(ancs, ancs + N + 1, -1);

    q.push(s);
    dist[s] = 0;

    int i;

    for ( ; !q.empty(); ) {
        int now = q.top();
        q.pop();

        for (i = 0; i < (int) graph[now].size(); i++) {
            int next = graph[now][i];

            if (dist[now] + cst[now][next] < dist[next] && cap[now][next] - res[now][next] > 0) {
                dist[next] = dist[now] + cst[now][next];
                ancs[next] = now;
                q.push(next);
            }
        }
    }

    Int curr_flow = INF;
    int v = t, u = ancs[t];

    for ( ; u != -1; ) {
        if (res[v][u]) {
            chmin(curr_flow, res[v][u]);
        } else {
            chmin(curr_flow, cap[u][v] - res[u][v]);
        }
        v = u;
        u = ancs[u];
    }

    end_flow[t] = curr_flow;

    return dist[t] != INF;
}


pair<Int, Int> flow(int s, int t) {
    pair<Int, Int> ans = make_pair(0LL, 0LL);

    for ( ; augment_path(s, t); ) {
        int v = t, u = ancs[t];

        Int iter_flow = end_flow[t];
        ans.first += iter_flow;

        for ( ; v != -1; ) {
            if (res[v][u]) {
                res[v][u] -= iter_flow;
                ans.second -= iter_flow * cst[v][u];
            } else {
                res[u][v] += iter_flow;
                ans.second += iter_flow * cst[u][v];
            }

            v = u;
            u = ancs[u];
        }
    }

    return ans;
}

int main(void) {
    freopen("i.in", "r", stdin);
    int i;
    int j;

    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        for (i = 0; i < MAXN; i++) {
            graph[i].clear();
            for (j = 0; j < MAXN; j++) {
                cap[i][j] = res[i][j] = cst[i][j] = 0LL;
            }
        }

        for (i = 0; i < M; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }

        cin >> D >> K;

        for (i = 0; i < M; i++) {
            add_edge(A[i], B[i], C[i], K);
            add_edge(B[i], A[i], C[i], K);
        }

        add_edge(0, 1, 0, D);

        pair<Int, Int> fl = flow(0, N);

        if (fl.first == D) {
            printf("%lld\n", fl.second);
        } else {
            puts("Impossible.");
        }
    }

    return 0;
}
