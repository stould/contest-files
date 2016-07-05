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

int T, N;
Int P[100005];

int child[MAXN][2];
int n;
	
void resetTrie() {
    n = 1;
    memset(child, 0, sizeof(child));
}

void addWord(Int x) {
    int now = 0;
	
    for (int i = 31; i >= 0; i--) {
        int letter_pos = (x & (1LL << (Int) i)) != 0;
	
        if (!child[now][letter_pos]) {
            child[now][letter_pos] = n++;
        }		
        now = child[now][letter_pos];
    }
}

Int query(Int x) {
    Int value = 0;
		
    int now = 0;

    for (int i = 31; i >= 0; i--) {
        int wish = (x & (1LL << (Int) i)) != 0LL;
        
        if (child[now][wish ^ 1]) {
            value += (1LL << i);
            now = child[now][wish ^ 1];
        } else if (child[now][wish]) {
            now = child[now][wish];
        } else {
            break;
        }
    }

    return value;
}

int main(void) {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        cin >> N;

        Int ans = 0;
        Int all = 0;

        addWord(0LL);
		
        for (int i = 0; i < N; i++) {
            scanf("%lld", &P[i]);

            all ^= P[i];		
            chmax(ans, query(all));
            addWord(all);
        }
        chmax(ans, query(0LL));
        resetTrie();
        printf("%lld\n", ans);
    }
	
    return 0;
}
