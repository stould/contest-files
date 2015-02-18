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

int T;
string S;

int main(void) {
    cin >> T;
    
    for ( ; T--; ) {
        cin >> S;        
        
        set<pair<int, int> > vp;
        set<pair<int, int> >::iterator it;
        
        for (int i = 1; i <= 12; i++) {
            for (int j = 1; j <= 12; j++) {
                if (i * j == 12) {
                    char buff[i][j];
                    int mem[j], id = 0;
                    
                    memset(mem, 0, sizeof(mem));                    
                    
                    for (int a = 0; a < i; a++) {
                        for (int b = 0; b < j; b++) {
                            buff[a][b] = S[id++];                            
                            
                            if (buff[a][b] == 'X') {
                                mem[b] += 1;                               
                                
                                if (mem[b] == i) {
                                    vp.insert(make_pair(i, j));
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << (int) vp.size() << " ";
        
        for (it = vp.begin(); it != vp.end(); it++) {
            cout << it->first << "x" << it->second << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
