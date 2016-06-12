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

const int MAXN = 1000005;
const int INF = INT_MAX / 5;

string S[100];
int belong[MAXN];
int N;

// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm

//Usage:
// Fill str with the characters of the string.
// Call SuffixSort(n), where n is the length of the string stored in str.
// That's it!

//Output:
// pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// rnk = The inverse of the suffix array. rnk[i] = the index of the suffix str[i..n)
//        in the pos array. (In other words, pos[i] = k <==> rnk[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if rnk[i] < rnk[j]

int str[MAXN]; //input
int rnk[MAXN], pos[MAXN]; //output
int cnt[MAXN], nxt[MAXN]; //internal
bool bh[MAXN], b2h[MAXN];

bool smaller_first_char(int a, int b){
    return str[a] < str[b];
}

void SuffixSort(int n){
 //sort suffixes according to their first character
    for (int i=0; i<n; ++i){
        pos[i] = i;
    }
    sort(pos, pos + n, smaller_first_char);
 //{pos contains the list of suffixes sorted by their first character}

    for (int i=0; i<n; ++i){
        bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
        b2h[i] = false;
    }

    for (int h = 1; h < n; h <<= 1){
   //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
        int buckets = 0;
        for (int i=0, j; i < n; i = j){
            j = i + 1;
            while (j < n && !bh[j]) j++;
            nxt[i] = j;
            buckets++;
        }
        if (buckets == n) break; // We are done! Lucky bastards!
   //{suffixes are separted in buckets containing strings starting with the same h characters}

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


// Begin of the O(n) longest common prefix algorithm
int lcp[MAXN];
// lcp[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// lcp[0] = 0
void getLcp(int n){
    for (int i=0; i<n; ++i) rnk[pos[i]] = i;
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

int tree[4 * MAXN];
int lazy[4 * MAXN];

void goDown(int node, int l, int r) {    
    if (lazy[node]) {
        tree[node] += lazy[node];
        
        if (l != r) {
            lazy[2 * node]     += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        } 
    }
    lazy[node] = 0;
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = lcp[l];
    } else {
        int m = (l + r) / 2;
        
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);
        
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

Int query(int node, int l, int r, int bl, int br) {
    goDown(node, l, r);
    if (l >= bl && r <= br) {
        return tree[node];
    } else if (l > br || r < bl) { 
        return INF;
    } else {
        int m = (l + r) / 2;
        
        Int a = query(2 * node, l, m, bl, br);
        Int b = query(2 * node + 1, m + 1, r, bl, br);
        
        return min(a, b);
    }
}

void update(int node, int l, int r, int bl, int br, Int value) {    
    goDown(node, l, r);
    if (l > r) {
        return;
    } else if (l > br || r < bl) {
        return;
    } else if (l >= bl && r <= br) {
        lazy[node] = value;    
        goDown(node, l, r);
    } else {
        int m = (l + r) / 2;       
        
        update(2 * node, l, m, bl, br, value);
        update(2 * node + 1, m + 1, r, bl, br, value);
        
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }    
}


int main(void) {
    while (cin >> N && N != 0) {
        string all = "";
        map<string, int> unique;
        
        for (int i = 0; i < N; i++) {
            cin >> S[i];

            unique[S[i]] += 1;

            all += S[i];

            if (i != N - 1) {
                all += "$";
            }
        }        

        int L = (int) all.size();
        int ps = 0;
        
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

        set<Int> seen;
        
        for (int i = N - 1; i < L; i++) {
            if (lcp[i] == (int) S[belong[pos[i - 1]]].size()) {
                unique[S[belong[pos[i - 1]]]] = 1000000;
            }
            if (lcp[i] == (int) S[belong[pos[i]]].size()) {
                unique[S[belong[pos[i]]]] = 1000000;
            }            
        }

        build(1, 0, L - 1);
        
        while (1) {
            int gr = 0;
            for (int i = N - 1; i < L; i++) {
                int li = query(1, 0, L - 1, i, i);

                gr = max(gr, li);
                
                int j = i + 1;
                Int mask = (1LL << belong[pos[i]]);
                int sm = INT_MAX;
                
                while (j < L) {
                    int lj = query(1, 0, L - 1, j, j);

                    if (lj <= 0) break;
                    
                    gr = max(gr, lj);
                    sm = min(sm, lj);
                    
                    mask |= (1LL << belong[pos[j]]);
                    j += 1;
                }
                if (j != i + 1) {
                    update(1, 0, L - 1, i + 1, j - 1, -sm);
                    seen.insert(mask);
                }
                i = j - 1;
            }
            if (gr == 0) break;
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
