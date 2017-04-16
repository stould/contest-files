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

int N;
set<int> tree[MAXN];
int height[MAXN];
int subSize[MAXN];
int treeSize;
int centroidParent[MAXN];
vector<int> centroidNext[MAXN];
char label[MAXN];
int centroidRoot;

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

    if (node == last_centroid) {
        centroidParent[curr_centroid] = curr_centroid;
        centroidRoot = curr_centroid;
    } else {
        centroidParent[curr_centroid] = last_centroid;
        centroidNext[last_centroid].push_back(curr_centroid);
    }

    for (auto& next : tree[curr_centroid]) {
        tree[next].erase(curr_centroid);
        centroid(next, curr_centroid);
    }

    tree[curr_centroid].clear();
}

void dfsLabel(int node, int pos) {
    if (node < 0) return;
    label[node] = char('A' + pos);

    for (auto& next : centroidNext[node]) {
        dfsLabel(next, pos + 1);
    }    
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        tree[a].insert(b);
        tree[b].insert(a);
    }

    centroid(1, 1);

    dfsLabel(centroidRoot, 0);

    for (int i = 1; i <= N; i++) {
        if (i > 1) printf(" ");
        printf("%c", label[i]);
    }
    printf("\n");
    return 0;
}
