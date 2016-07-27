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

const int MAXN = 100005;
const int ALPHA_LEN = 256;

int N, M;
string S;
int cnt;
int term[MAXN];
int matchPos[MAXN];
int sig[MAXN][260];
int T[MAXN];

void add(string& arg) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) arg[i];
        if (sig[x][c] == 0) term[cnt] = 0, sig[x][c] = cnt++;
        x = sig[x][c];
        //cerr << arg[i] << " " << x << endl;;
    }
    //cerr << endl;
    term[x] = 1;
    matchPos[x] = arg.size();
}


void aho (){
    queue <int> Q;
    for (int i = 0; i < ALPHA_LEN; i++){
        int v = sig[0][i];

        if (v) {
            Q.push (v);
            T[v] = 0;
        }
    }
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        
        for (int i = 0; i < ALPHA_LEN; i++){
            int x = sig[u][i];
            if (x == 0) continue;
            
            int v = T[u];
            while (sig[v][i] == 0 && v != 0) v = T[v];
            int y = sig[v][i];

            Q.push(x);
            T[x] = y;
            term[x] |= term[y];
        }
    }
}

int busca (string& arg){
    int n = (int) arg.size();
    int ans = -1;
    
    int pos = 0;
    
    for (int i = 0; i < n; i++){
        
        if (sig[pos][(int) arg[i]] != 0){
            pos = sig[pos][(int) arg[i]];
        } else {
            while (pos != 0 && sig[pos][(int) arg[i]] == 0) {
                pos = T[pos];
            }
            pos = sig[pos][(int) arg[i]];
        }
        if (matchPos[pos]) {
            ans = i;                
        }                    
    }
    return ans;
}


int main(void) {
    cin >> N;
    getline(cin, S);
    
    cnt = 1;
    for (int i = 0; i < N; i++) {
        getline(cin, S, '\n');
        S = S.substr(0, S.size() - 1);
        reverse(S.begin(), S.end());
        add(S);
    }
    
    cin >> M;
    getline(cin, S);
    
    aho();

    for (int i = 0; i < M; i++) {
        getline(cin, S, '\n');
        S = S.substr(0, S.size() - 1);
        reverse(S.begin(), S.end());
        
        int ans = busca(S);

        if (ans != -1) {
            cout << i + 1 << " " << S.size() - ans << endl;
            return 0;
        }
    }

    cout << "Passed" << endl;
    return 0;
}
