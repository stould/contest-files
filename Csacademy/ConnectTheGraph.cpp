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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N, M;
vector<int> G[MAXN];
int mark[MAXN];
int vis[MAXN];
set<pair<int, int> > br;
int dfsct, num[MAXN], low[MAXN], parent[MAXN];
int deg[MAXN];

void dfs(int node, int cmp) {
    mark[node] = cmp;
    
}

void bridge(int atual){
    num[atual] = low[atual] = dfsct++;
    
    for (int i = 0; i < (int) G[atual].size(); i++) {        
        int next = G[atual][i];
        
        if (num[next] == -1){
            parent[next] = atual;
            bridge(next);
            if (low[next] > num[atual]){
                br.insert({atual, next});                             
            }
            low[atual] = min(low[atual], low[next]);
        }else if(next != parent[atual]){
            low[atual] = min(low[atual], num[next]);
        }
    }
}

 
void countBridges(){
    dfsct = 0;
    for (int i = 0; i < N; i++){
        num[i] = -1;
        parent[i] = 0;
    }
    for (int i = 0; i < N; i++){
        if(num[i] == -1) bridge(i);
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;

        cin >> a >> b;

        a -= 1;
        b -= 1;

        deg[a] += 1;
        deg[b] += 1;
        
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    countBridges();

    return 0;
}
