#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 1010;

int N;
string S;
bool vis[MAXN];

bool can(int s, int t) {
    int p = s;
    
    memset(vis, 0, sizeof(vis));   
    
    while (1) {        
        if (S[p] == '.' || vis[p]) {
            return p == t;
        }   

        vis[p] = true;
        
        if (S[p] == '.') return false;
        int last = p;
        
        if (S[p] == 'L') {
            p = p - 1;
        } else {
            p = p + 1;
        }
        if (vis[p] && last == t) return true;
    }
}

int main(void) {
    cin >> N >> S;    
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (can(i, j)) {
                cout << i + 1 << " " << j + 1 <<"\n";
                return 0;            
            }
            if (can(j, i)) {
                cout << j + 1 << " " << i + 1 <<"\n";
                return 0;            
            }
        }
    }
    
    return 0;
}
