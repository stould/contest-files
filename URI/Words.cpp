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

const int MAX_L = 2;
const int MAXN = 510;

int N, M;
string A[30], B[30];
int trie[2][MAXN][MAX_L];
int term[2][MAXN];
int cnt[2];

void add(int id, string& arg) {
    int pos = 0;

    for (int i = 0; i < (int) arg.size(); i++) {
        int val = arg[i] - '0';
        
        if (trie[id][pos][val] == 0) {
            trie[id][pos][val] = cnt[id]++;
        }
        pos = trie[id][pos][val];
    }

    term[id][pos] = 1;
}

bool func(int pa, int pb, int iter) {
    if (term[0][pa] && term[1][pb]) {
        return true;
    } else if (iter > 30) {
        return false;
    } else {
        bool ans = false;

        vector<int> va, vb;

        va.push_back(pa);
        vb.push_back(pb);

        if (term[0][pa]) va.push_back(0);
        if (term[1][pb]) vb.push_back(0);        
        
        for (int ia = 0; ia < (int) va.size(); ia++) {
            for (int ib = 0; ib < (int) vb.size(); ib++) {
                for (int i = 0; !ans && i <= 1; i++) {
                    if (trie[0][va[ia]][i] != 0 && trie[1][vb[ib]][i] != 0) {
                        ans |= func(trie[0][va[ia]][i], trie[1][vb[ib]][i], iter + 1);                
                    }
                }
            }
        }
        return ans;
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> N >> M) {
        cnt[0] = cnt[1] = 1;
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            add(0, A[i]);
        }
        for (int i = 0; i < M; i++) {
            cin >> B[i];
            add(1, B[i]);
        }

        bool ans = func(0, 0, 0);
                
        if (ans) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAX_L; j++) {
                trie[0][i][j] = 0;
                trie[1][i][j] = 0;
            }
            term[0][i] = 0;
            term[1][i] = 0;
        } 
    }
    return 0;
}
