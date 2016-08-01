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

string S;
int N;
int str[MAXN]; //input
int rnk[MAXN], pos[MAXN]; //output
int cnt[MAXN], nxt[MAXN]; //internal
bool bh[MAXN], b2h[MAXN];

bool smaller_first_char(int a, int b){
    return str[a] < str[b];
}

void SuffixSort(int n){
    for (int i=0; i<n; ++i){
        pos[i] = i;
    }
    sort(pos, pos + n, smaller_first_char);

    for (int i=0; i<n; ++i){
        bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
        b2h[i] = false;
    }

    for (int h = 1; h < n; h <<= 1){
        int buckets = 0;
        for (int i=0, j; i < n; i = j){
            j = i + 1;
            while (j < n && !bh[j]) j++;
            nxt[i] = j;
            buckets++;
        }
        if (buckets == n) break; // We are done! Lucky bastards!

        for (int i = 0; i < n; i = nxt[i]){
            cnt[i] = 0;
            for (int j = i; j < nxt[i]; ++j){
                rnk[pos[j]] = i;
            }
        }

        cnt[rnk[n - h]]++;
        b2h[rnk[n - h]] = true;
        for (int i = 0; i < n; i = nxt[i]){
            for (int j = i; j < nxt[i]; ++j){
                int s = pos[j] - h;
                if (s >= 0){
                    int head = rnk[s];
                    rnk[s] = head + cnt[head]++;
                    b2h[rnk[s]] = true;
                }
            }
            for (int j = i; j < nxt[i]; ++j){
                int s = pos[j] - h;
                if (s >= 0 && b2h[rnk[s]]){
                    for (int k = rnk[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                }
            }
        }
        for (int i=0; i<n; ++i){
            pos[rnk[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i=0; i<n; ++i){
        rnk[pos[i]] = i;
    }
}

int lcp[MAXN];

void getLcp(int n){
    for (int i=0; i<n; ++i) rnk[pos[i]] = i;
    lcp[0] = 0;
    for (int i=0, h=0; i<n; ++i){
        if (rnk[i] > 0){
            int j = pos[rnk[i]-1];
            while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
            lcp[rnk[i]] = h;
            if (h > 0) h--;
        }
    }
}

int tree[MAXN][22];
Int maskTree[MAXN][22];
int len[MAXN];
int ppp[MAXN];

void build() {
    int pw = 1;
    int base = 2;
 
    for (int i = 0; i <= N; i++) {
        tree[i][0] = lcp[i];
    }
  
    while (base <= N) {
        for (int i = 0; i + base / 2 - 1 <= N; i++) {
            int before = base / 2;		
            tree[i][pw] = min(tree[i][pw - 1], tree[i + before][pw - 1]);
        }    
        pw += 1;
        base *= 2;
    }

    pw = 0;
    int bs = 1;
    
    for (int i = 1; i <= N; i++) {
        if (bs * 2 == i) {
            pw += 1;
            bs *= 2;
        }
        len[i] = pw;
        ppp[i] = bs;        
    }
}

int query(int l, int r) {
    int ll = r - l + 1;

    if (ll == 1) return tree[l][0];

    //cout << l << " " << r << " " << len[ll] << " " << ppp[ll] << endl;
    //cout << r - ppp[ll] + 1 << endl;
    int a = tree[l][len[ll]];
    int b = tree[r - ppp[ll] + 1][len[ll]];
 
    return min(a, b);
}

int funcL(int l, int r, int rbound, int val) {
    int ans = rbound;
    
    while (l <= r) {
        int m = l + (r - l) / 2;

        int curr = query(m, rbound);

        if (curr < val) {
            l = m + 1;
        } else {
            ans = m;
            r = m - 1;
        }
    }
    return ans;
}

int funcR(int l, int r, int lbound, int val) {
    int ans = lbound;
    
    while (l <= r) {
        int m = l + (r - l) / 2;

        int curr = query(lbound, m);

        if (curr < val) {
            r = m - 1;
        } else {
            ans = m;
            l = m + 1;
        }
    }
    return ans;
}


int main(void) {
    cin >> S;

    N = (int) S.size();
    
    for (int i = 0; i < N; i++) {
	str[i] = S[i];
    }
    
    SuffixSort(N);
    getLcp(N);

    build();
    
    Int ans = N;
    
    for (int i = 1; i <= N; i++) {
        if (lcp[i] > 0) {
            int lbound = funcL(1, i, i, lcp[i]) - 1;
            int rbound = funcR(i, N, i, lcp[i]);
            
            //cout << lcp[i] << " " << lbound << " " << rbound << endl;
            
            ans = max(ans, (Int) lcp[i] * (rbound - lbound + 1));
        }
    }
    cout << ans << endl;
    
    return 0;
}
