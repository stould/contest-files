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

const int MAXN = 3200005;                 
const int MAX_LEN = 3;

int T, N, K;
int P[100005];

int child[MAXN][2];
int conta[MAXN][2];
int n;
	
void resetTrie() {
    n = 1;
    memset(child, -1, sizeof(child));
    memset(conta, 0, sizeof(conta));
}

void addWord(Int x) {
    int now = 0;
	
    for (int i = 25; i >= 0; i--) {
        int letter_pos = (x & (1 << i)) != 0;
        if (child[now][letter_pos] == -1) {
            child[now][letter_pos] = n++;
            conta[now][letter_pos] += 1;
        }		
        now = child[now][letter_pos];
    }
}

Int query(Int x, int pos, int trie_pos, int value, int buff) {
    if (value >= K) return 0;
    if (pos < 0) {
        return buff;
    }
		
    int wish = (x & (1 << pos)) != 0;
    Int ans = 0;

    if ((wish ^ 1) > 1) {
        cout << "EE\n";
    }

    
    if (child[trie_pos][wish ^ 1] != -1) {
        ans += query(x, pos - 1, child[trie_pos][wish ^ 1], value + (1 << pos), conta[trie_pos][wish ^ 1]);
    }
    if (child[trie_pos][wish] != -1) {
        ans += query(x, pos - 1, child[trie_pos][wish], value, conta[trie_pos][wish]);
    }
    
    return ans;
}

int main(void) {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        resetTrie();
        cin >> N >> K;

        Int ans = 0;
        Int all = 0;
        
        addWord(0LL);
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &P[i]);

            all ^= P[i];		
            ans += query(all, 25, 0, 0, 0);
            //cout << query(all, 31, 0, 0) << "\n";
            addWord(all);
        }
        //ans += query(all, 20, 0, 0, 0);
        printf("%lld\n", ans);
    }
	
    return 0;
}
