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
typedef unsigned uint;

const int MAXN = 550;

int T;
int N, M;
string str[MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<pair<int, int> > pt;
vector<pair<int, int> >::iterator it;

void func(void) {
    int i;
    int j;
    int k;    
    int x;
    
    for ( ; !pt.empty(); ) {
        string cp[N];
        
        for (i = 0; i < N; i++) cp[i] = str[i];
        
        bool done = false;
        vector<pair<int, int> > buff;

        for (it = pt.begin(); it != pt.end(); it++) {        
            i = it->first;
            j = it->second;           
            
            if (str[i][j] == '*' || str[i][j] == '#') {
                cp[i][j] = str[i][j];
            } else if (str[i][j] >= 'a' && str[i][j] <= 'z') {
                for (k = 0; k < 4; k++) {
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    
                    if (ii >= 0 && jj >= 0 && ii < N && jj < M) {                            
                        if (cp[ii][jj] == '.') {
                            cp[ii][jj] = str[i][j];
                            buff.push_back(make_pair(ii, jj));     
                        } else if (cp[ii][jj] >= 'a' && cp[ii][jj] <= 'z' && str[ii][jj] == '.' && str[i][j] != cp[ii][jj]  ) {
                            cp[ii][jj] = '*';
                        }                    
                    }
                }
            }
        }

        pt = buff;
        
        for (i = 0; i < N; i++) {
            if (str[i] != cp[i]) {
                done = true;
            }
            str[i] = cp[i];
        }
    }
}

int main(void) {
    T = in();
    
    int i;  
    int j;
    
    for ( ; T--; ) {
        N = in();
        M = in();
        
        for (i = 0; i < N; i++) {
            cin >> str[i];
            for (j = 0; j < M; j++) if (str[i][j] >= 'a' && str[i][j] <= 'z') {
                pt.push_back(make_pair(i, j));   
            }
        }
        
        func();
        
        for (i = 0; i < N; i++) {
            cout << str[i] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
