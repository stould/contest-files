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

const int MAXN = 11;

int T, P;
int N[MAXN], M[MAXN];
string S[MAXN][MAXN][MAXN];
int ans[3][3];
vector<string> tr;
char buff[MAXN];

inline bool match(string& a, string& b) {   
    for (int i = 0; i < 2; i++) {
        if (a[i] != '_' && b[i] != '_') {
            if (a[i] != b[i]) return false;
        }
    }
    return true;
}

inline bool fitPiece(int i) {
    for (int j = 0; j < 3 - N[i]; j++) {
        for (int k = 0; k < 3 - M[i]; k++) {
            bool inner_fine = true;                    
            for (int a = 0; a < N[i]; a++) {
                for (int b = 0; b < M[i]; b++) {
                    if (!match(tr[ans[j + a][k + b]], S[i][a][b])) {
                        inner_fine = false;
                    }
                }
            }                    
            if (inner_fine) {
                return true;
            }
        }
    }
    return false;
}

bool used[10];

bool rec(int si, int sj) {
    if (si == 3) {
        for (int i = 0; i < P; i++) {
            if (!fitPiece(i)) {
                return false;
            }
        }
        return true;
    } else {        
        for (int i = 0; i < 9; i++) {
            if (!used[i]) {
                ans[si][sj] = i;
                used[i] = true;
                bool st = rec((3*si+sj+1)/3,(sj+1)%3);
                if (st) return true;
                used[i] = false;
            }
        }
        return false;
    }
}

inline void rd(int &x) {
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

int main(void) {
    rd(T);
    
    string AS = "SRT";
    string BS = "VSC";    
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tr.push_back(string(1, AS[i]) + string(1, BS[j]));
        }
    }

    sort(tr.begin(), tr.end());
    
    for (int t = 1; t <= T; t++) {
        //scanf("%d", &P);
        rd(P);
        
        for (int i = 0; i < P; i++) {
            rd(N[i]);
            rd(M[i]);
            //scanf("%d%d", &N[i], &M[i]);

            for (int j = 0; j < N[i]; j++) {
                for (int k = 0; k < M[i]; k++) {
                    scanf("%s", buff);
                    S[i][j][k] = string(buff);
                }
            }
        }

        printf("Puzzle #%d:\n", t);
        memset(used, false, sizeof(used));
        rec(0, 0);      
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j) printf(" ");
                printf("%s", tr[ans[i][j]].c_str());
            }
            printf("\n");
        }
    }
    return 0;
}
