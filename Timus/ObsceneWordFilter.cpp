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

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;
const int ALPHA_LEN = 256;
const int INF = 1001010010;
int N, M;
string W[10005];
string S;
int cnt;
vector<int> term[MAXN];
int matchPos[MAXN];
int sig[MAXN][260];
int T[MAXN];

void add(string& arg, int id) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) arg[i] + 128;
        if (sig[x][c] == 0) {
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
        //cerr << arg[i] << " " << x << endl;;
    }
    //cerr << endl;
    term[x].push_back(id);;
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
            term[x].insert(term[x].begin(), term[y].begin(), term[y].end());
        }
    }
}

int busca (string& arg){
    int n = (int) arg.size();
    int ans = INF;
    
    int pos = 0;
    
    for (int i = 0; i < n; i++){
        int val = (int) arg[i] + 128;
        
        if (sig[pos][val] != 0){
            pos = sig[pos][val];
        } else {
            while (pos != 0 && sig[pos][val] == 0) {
                pos = T[pos];
            }
            pos = sig[pos][val];
        }
        //cout << i << " " << arg[i] << " " << pos << " " << term[pos].size() << "\n";
        for (int j = 0; j < (int) term[pos].size(); j++) {
            chmin(ans, i - (int) W[term[pos][j]].size() + 2);
        }                        
    }
    if (ans == INF) {
        ans = -1;
    }
    return ans;
}


int main(void) {
    cin >> N;
    getline(cin, S);
    
    cnt = 1;
    
    for (int i = 0; i < N; i++) {
        getline(cin, W[i], '\n');
        W[i] = W[i].substr(0, W[i].size() - 1);
        //cout << W[i] << endl;
        add(W[i], i);
    }
    
    cin >> M;
    getline(cin, S);
    
    aho();

    for (int i = 0; i < M; i++) {
        getline(cin, S, '\n');
        //S = S.substr(0, S.size() - 1);
        
        int ans = busca(S);

        if (ans != -1) {
            cout << i + 1 << " " << ans << endl;
            return 0;
        }
    }

    cout << "Passed" << endl;
    return 0;
}
