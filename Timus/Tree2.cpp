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

const int INF = INT_MAX / 5;
const int MAXN = 20020;
const int MAX_LOG = 20;

int N, M;

set<int> tree[MAXN];
int height[MAXN];
int subSize[MAXN];
int treeSize;
int centroidParent[MAXN];
unordered_map<int, vector<int> > minDist[MAXN];

int dist[MAXN];
int lca[MAXN][MAX_LOG];

void dfs(int node, int curr_cost, int p) {
    dist[node] = curr_cost;
    lca[node][0] = p;
    
    for (int i = 1; i < MAX_LOG; i++) {
        lca[node][i] = lca[lca[node][i - 1]][i - 1];        
    }

       
    for (auto& next : tree[node]) {
        if (next == p) continue;
        
        height[next] = height[node] + 1;

        dfs(next, curr_cost + 1, node);
    }
}

int getLca(int p, int q) {
    if (height[q] > height[p]) {
        swap(p, q);
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (height[p] - (1 << i) >= height[q]) {
            p = lca[p][i];
        }
    }
    
    if (p == q) return p;

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (lca[p][i] != -1 && lca[p][i] != lca[q][i]) {
            p = lca[p][i];
            q = lca[q][i];
        }
    }
    return lca[p][0];
}

int getDist(int p, int q) {
    return dist[p] + dist[q] - 2 * dist[getLca(p, q)];
}

void dfsCounting(int node, int p) {
    subSize[node] = 1;
    treeSize += 1;
       
    for (auto& next : tree[node]) {
        if (next == p) continue;
        dfsCounting(next, node);

        subSize[node] += subSize[next];
    } 
}

int dfsCentroid(int node, int p) {
    for (auto& next : tree[node]) {
        if (next == p) continue;

        if (2 * subSize[next] >= treeSize) {
            return dfsCentroid(next, node);
        }
    }
    
    return node;
}

void centroid(int node, int last_centroid) {
    treeSize = 0;
    dfsCounting(node, node);

    int curr_centroid = dfsCentroid(node, node);

    //cout << curr_centroid << " " << last_centroid << endl;
    if (node == last_centroid) {
        centroidParent[curr_centroid] = curr_centroid;
    } else {
        centroidParent[curr_centroid] = last_centroid;
    }

    for (auto& next : tree[curr_centroid]) {
        tree[next].erase(curr_centroid);
        centroid(next, curr_centroid);
    }

    tree[curr_centroid].clear();
}

void update(int node) {
    int base = node;
    
    while (1) {
        minDist[node][getDist(node, base)].push_back(base);
        if (node == centroidParent[node]) {
            break;
        }
        node = centroidParent[node];
    }
}

int query(int node, int len) {
    int ans = 0;
    int curr = node;
    bool done = false;
    
    while (!done) {
        int curr_dist = getDist(node, curr);

        //cout << curr << " " << curr_dist << " " << len - curr_dist << " " << minDist[curr][len - curr_dist] << "\n";
        if (minDist[curr].find(len - curr_dist) != minDist[curr].end()) {
            for (int i = 0; i < (int) minDist[curr][len - curr_dist].size(); i++) {
                if (getDist(node, minDist[curr][len - curr_dist][i]) == len) {
                    ans = minDist[curr][len - curr_dist][i];
                    done = true;
                    break;
                }
            }
        }
        
        if (curr == centroidParent[curr]) {
            break;
        }
        
        curr = centroidParent[curr];
    }
    
    return ans;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int a, b;

        cin >> a >> b;
        
        tree[a].insert(b);
        tree[b].insert(a);
    }
    
    dfs(1, 0, 1);
    centroid(1, 1);

    for (int i = N; i >= 0; i--) {
        update(i);
    }

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        cout << query(a, b) << "\n";
    }
    return 0;
}
