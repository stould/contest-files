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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 599905;
const int INF = INT_MAX / 5;

string S[61];
int belong[MAXN];
int N, L;

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
// End of suffix array algorithm


int lcp[MAXN];

void getLcp(int n){
    //for (int i=0; i<n; ++i) rnk[pos[i]] = i;
    lcp[0] = 0;
    for (int i=0, h=0; i<n; ++i){
        if (rnk[i] > 0){
            int j = pos[rnk[i]-1];
            while (i + h < n && j + h < n && str[i+h] == str[j+h] && str[i + h] != '$' && str[j + h] != '$') h++;
            lcp[rnk[i]] = h;
            if (h > 0) h--;
        }
    }
}
// End of the longest common prefix algorithm

int tree[MAXN][22];
Int maskTree[MAXN][22];
int len[MAXN];
int ppp[MAXN];

void build() {
    int pw = 1;
    int base = 2;
 
    for (int i = 0; i < L; i++) {
        tree[i][0] = lcp[i];
        maskTree[i][0] = (1LL << (Int) belong[pos[i]]);
    }
  
    while (base <= L) {
        for (int i = 0; i + base / 2 - 1 < L; i++) {
            int before = base / 2;		
            tree[i][pw] = min(tree[i][pw - 1], tree[i + before][pw - 1]);
            maskTree[i][pw] = maskTree[i][pw - 1] | maskTree[i + before][pw - 1];
        }    
        pw += 1;
        base *= 2;
    }

    pw = 0;
    Int bs = 1;
    
    for (int i = 1; i < L; i++) {
        if (bs * 2LL == i) {
            pw += 1;
            bs *= 2LL;
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

Int queryMask(int l, int r) {
    int ll = r - l + 1;

    if (ll == 1) return maskTree[l][0];
       
    Int a = maskTree[l][len[ll]];
    Int b = maskTree[r - ppp[ll] + 1][len[ll]]; 
    
    return a | b;
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
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> N && N != 0) {
        string all = "";
        unordered_map<string, int> unique;
        int ps = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> S[i];

            unique[S[i]] += 1;

            all += S[i];

            if (i != N - 1) {
                all += "$";
            }
        }        

        L = (int) all.size();

        for (int i = 0; i < L; i++) {
            str[i] = all[i];

            if (all[i] == '$') {
                ps += 1;
                continue;
            }

            belong[i] = ps;     
        }

        SuffixSort(L);
        getLcp(L);

        build();        

        set<Int> seen;
        
        for (int i = N - 1; i < L; i++) {
            if (lcp[i] == (int) S[belong[pos[i - 1]]].size()) {
                unique[S[belong[pos[i - 1]]]] = 1000000;
            }
            if (lcp[i] == (int) S[belong[pos[i]]].size()) {
                unique[S[belong[pos[i]]]] = 1000000;
            }            
        }
        /*
          vector<pair<int, int> > vs;
        
          for (int i = 0; i < L; i++) {
          vs.push_back(make_pair(rnk[i], i));              
          }
        
          sort(vs.begin(), vs.end());
          
          for (int i = N - 1; i < L; i++) {
              cout << (1LL << belong[pos[i]]) << " " << queryMask(i, i) <<"\n";
              //cout << i << "    " << lcp[i] << " " << all.substr(vs[i].second, all.size() - vs[i].second) << "\n";
              //cout << lcp[i] << "\n";
          }
          cout << "\n";
          
        */

        
        for (int i = N - 1; i < L; i++) {
            //cout << belong[pos[i]] << " " << (1LL << belong[pos[i]]) << " " << queryMask(1, 0, L - 1, i, i) << "\n";
            if (lcp[i] > 0) {
                int lbound = funcL(N - 1, i, i, lcp[i]) - 1;
                int rbound = funcR(i, L - 1, i, lcp[i]);
                
                //cout << lbound << " " << i << " " << rbound << " => " << queryMask(lbound, rbound) << "\n";
                seen.insert(queryMask(lbound, rbound));
            }              
        }
        
        for (int i = 0; i < N; i++) {
            if (unique[S[i]] == 1) {
                seen.insert(1LL << (Int) i);
            }
        }
        cout << seen.size() << "\n";
    }
    return 0;
}
