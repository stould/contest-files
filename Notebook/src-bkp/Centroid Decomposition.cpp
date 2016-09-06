set<int> tree[MAXN];
int height[MAXN];
int subSize[MAXN];
int treeSize;
int centroidParent[MAXN];
multiset<int> minDist[MAXN];

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
        minDist[node].insert(getDist(node, base));
        if (node == centroidParent[node]) {
            break;
        }
        node = centroidParent[node];
    }
}

int query(int node) {
    int ans = INF;
    int curr = node;

    while (1) {
        int curr_dist = getDist(node, curr);

        if (minDist[curr].size() > 0) {
            ans = min(ans, curr_dist + *minDist[curr].begin());
        }

        if (curr == centroidParent[curr]) {
            break;
        }
        curr = centroidParent[curr];
    }
    
    return ans;
}
