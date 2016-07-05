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
 
const int MAXN = 200005;                 
const int MAX_LEN = 3;
 
int T, N, K;
int child[MAXN][2];
int conta[MAXN][2];
int n = 0;
int test = 0;

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}

void resetTrie() {
    if (n == 0) {
        memset(child, -1, sizeof(child));
    } else {
        for (int i = 0; i <= n; i++) {
            child[i][0] = child[i][1] = -1;
        }
    }
    n = 1;
}
 
void addWord(int x) {
    int now = 0;
    
    for (int i = 20; i >= 0; i--) {
        int letter_pos = (x & (1 << i)) != 0;
	
        if (child[now][letter_pos] == -1) {
            child[now][letter_pos] = n++;
            conta[now][letter_pos] = 0;
        }
        conta[now][letter_pos] += 1;
        now = child[now][letter_pos];
    }
}
 
Int query(Int x, int pos, int trie_pos, int value, int buff) {
    if (value >= K) return 0;
    if (pos < 0) return buff;
		
    int wish = (x & (1 << pos)) != 0;
    Int ans = 0;
    
    if (child[trie_pos][wish ^ 1] != -1) {
        ans += query(x, pos - 1, child[trie_pos][wish ^ 1], value + (1 << pos), conta[trie_pos][wish ^ 1]);        
    }
    if (child[trie_pos][wish] != -1) {
        ans += query(x, pos - 1, child[trie_pos][wish], value, conta[trie_pos][wish]);
    }
    
    return ans;
}
 
int main(void) {
    fastRead_int(T);

    for (int t = 0; t < T; t++) {
        resetTrie();
        
        fastRead_int(N);
        fastRead_int(K);
 
        Int ans = 0;
        Int all = 0;
        
        addWord(0LL);
        
        for (int i = 0; i < N; i++) {
            int P;
            fastRead_int(P);
 
            all ^= P;		
            ans += query(all, 20, 0, 0, 0);
            addWord(all);
        }

        printf("%lld\n", ans);
    }
	
    return 0;
}
 
