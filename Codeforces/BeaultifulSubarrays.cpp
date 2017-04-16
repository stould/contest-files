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

const int MAXN = 2200005;                 
const int MAX_LEN = 3;

int N;
int K;
int P[1000005];
int child[MAXN][2];
int cnt[MAXN];
int bs[60];
int n;
	
void resetTrie() {
    n = 1;
    memset(child, 0, sizeof(child));
}

void addWord(int x) {
    int now = 0;
	
    for (int i = 30; i >= 0; i--) {
        int letter_pos = (x >> i) & 1;
	
        if (!child[now][letter_pos]) {
            child[now][letter_pos] = n++;
        }        

        now = child[now][letter_pos];

        cnt[now] += 1;
    }
}

int query(int x, int bit, int trie_pos, int build) {
    if (bit < 0) {
        return build >= K ? cnt[trie_pos] : 0;
    } else if ((build | (bs[bit])) < K) {
        return 0;
    } else{
        int ans = 0;

        int ni = ((x >> bit) & 1);

        if (ni == 0) {
            if (child[trie_pos][1]) {
                ans += query(x, bit - 1, child[trie_pos][1], build | (1 << bit));
            }
            if (child[trie_pos][0]) {
                ans += query(x, bit - 1, child[trie_pos][0], build);
            }
        } else {
            if (child[trie_pos][0]) {
                ans += query(x, bit - 1, child[trie_pos][0], build | (1 << bit));
            }
            if (child[trie_pos][1]) {
                ans += query(x, bit - 1, child[trie_pos][1], build);
            }
        }
        
        return ans;
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> K;

    addWord(0);

    int all = 0;
    Int ans = 0;

    addWord(0);

    bs[0] = 1LL;
    
    for (int i = 1; i <= 30; i++) {
        bs[i] |= bs[i - 1] | (1 << i);
    }
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];

        all ^= P[i];
        addWord(all);
        
        ans += query(all, 30, 0, 0);
        cout << query(all, 30, 0, 0) << "\n";
    }
    
    cout << ans << "\n";
    return 0;
}
