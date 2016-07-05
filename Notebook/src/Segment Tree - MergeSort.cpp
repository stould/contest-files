vector<int> tree[MAXN << 2];
 
int lower_search(vector<int> &arr, int key){
    int lo = 0, hi = arr.size() - 1, ans = INF;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(arr[mid] >= key){
            ans = min(ans, mid);
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    return ans;
}
 
vector<int> merge(vector<int> &l, vector<int> &r){
    vector<int> ans;
    int idxl = 0;
    int idxr = 0;
    while(idxl < l.size() && idxr < r.size()){
        if(l[idxl] < r[idxr]){
            ans.push_back(l[idxl++]);
        }else if(l[idxl] > r[idxr]){
            ans.push_back(r[idxr++]);
        }else{
            ans.push_back(l[idxl++]);
            ans.push_back(r[idxr++]);
        }
    }
    while(idxl < l.size()){
        ans.push_back(l[idxl++]);
    }
    while(idxr < r.size()){
        ans.push_back(r[idxr++]);
    }
    return ans;
}
 
void build(int node, int l, int r){
    if(l > r) return;
    if(l == r){
        tree[node] = vector<int>(1, go[l]);
    }else{
        int mid = (r+l) >> 1;
        build(node << 1, l, mid);
        build((node << 1) | 1, mid+1, r);
        tree[node] = merge(tree[node << 1], tree[(node << 1) | 1]);
    }
}
 
//couting how many elements are greater than K
int query(int node, int l, int r, int bl, int br){
    if(l > br || r < bl || l > r){
        return 0;
    }else if(l >= bl && r <= br){
        //int greater = upper_bound(tree[node].begin(), tree[node].end(), br) - tree[node].begin();
        int greater = lower_search(tree[node], br+1);
        if(greater == INT_MAX){
            return 0;
        }else{
            return tree[node].size() - greater;
        }
    }else{
        int mid = (l+r) >> 1;
        int lq = query(node << 1, l, mid, bl, br);
        int rq = query((node << 1) | 1, mid+1, r, bl, br);
        return lq + rq;
    }
}
