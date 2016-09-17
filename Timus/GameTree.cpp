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

const int MAXN = 1010;

int N;
vector<int> tree[MAXN];
int outcome[MAXN];
int result[MAXN];
/*
bool canWin(int x, int level) {
    if (tree[x].empty()) {
        if (outcome[x] == 1) {
            result[x] = 1;
        } else {
            result[x] = 0;
        }
    } else {
        for (int i = 0; i < (int) tree[x].size(); i++) {
            int u = tree[x][i];            
            canWin(u, level + 1);
        }
    
        //play-1
        if (level % 2 == 1) {
            result[x] = 0;
        
            for (int i = 0; i < (int) tree[x].size(); i++) {
                int u = tree[x][i];
            
                if (result[u] == 1) {
                    result[x] = 1;
                    break;
                }
            }
        } else {
            result[x] = 1;
            
            for (int i = 0; i < (int) tree[x].size(); i++) {
                int u = tree[x][i];
                
                if (result[u] == 0) {
                    result[x] = 0;
                    break;
                }
            }
        }
    }
    //cout << x << " " << result[x] << endl;
    return result[x];
}
*/

bool dfs(int x, int level, int goal) {
    if (tree[x].empty()) {
        if (outcome[x] >= goal) {
            result[x] = 1;
        } else {
            result[x] = 0;
        }
    } else {
        for (int i = 0; i < (int) tree[x].size(); i++) {
            int u = tree[x][i];       
            dfs(u, level + 1, goal);
        }
    
        //play-1
        if (level % 2 == 1) {
            result[x] = 0;
        
            for (int i = 0; i < (int) tree[x].size(); i++) {
                int u = tree[x][i];
            
                if (result[u] == 1) {
                    result[x] = 1;
                    break;
                }
            }
        } else {
            result[x] = 1;
            
            for (int i = 0; i < (int) tree[x].size(); i++) {
                int u = tree[x][i];
                
                if (result[u] == 0) {
                    result[x] = 0;
                    break;
                }
            }
        }
    }
    //cout << x << " " << result[x] << endl;
    return result[x];
}

int main(void) {
    cin >> N;

    for (int i = 2; i <= N; i++) {
        string kind;
        int p;

        cin >> kind >> p;
        
        tree[p].push_back(i);
        
        if (kind == "L") {
            cin >> outcome[i];
        }
    }
    
    if (dfs(1, 1, 1)) {
        cout << "+1" << endl;
    } else if (dfs(1, 1, 0)) { 
        cout << "0" << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}
