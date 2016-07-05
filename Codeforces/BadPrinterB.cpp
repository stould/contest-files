#include <bits/stdc++.h>

using namespace std;

int N, G[50];
string S;
int qI[50];
string P[50];
map<string, vector<int> > mp;
bool has_q[50];
int ans = 0;

int to_int(string& S) {
    int ans = 0;
    
    for (int i = 0; i < (int) S.size(); i++) {
        ans = ans * 10 + (S[i] - '0');
    }
    
    return ans;
}

bool func(string a, string b) {
    int err = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        if (a[i] != b[i]) {
            if (b[i] != '?') {
                err += 1;
            }   
        }
    }
    return err == 0;
}

set<string> memo;

void rec(int id, int base) {
    if (G[base] <= ans) return;
    if (id == N) {
        ans = max(ans, G[base]);
    } else {        
        if (!has_q[id] || base == id) {
            rec(id + 1, base);
        } else {                  
            for (int i = 0; i <= 9; i++) {
                if (P[id][qI[id]] == '?') {
                    P[id][qI[id]] = '0' + i;       
                    
                    int toInt = to_int(P[id]);
                    
                    if (toInt >= 20110000 && toInt <= 20159999) {
                        if (!memo.count(P[id])) {
                            memo.insert(P[id]);
                            rec(id + 1, base);
                            memo.erase(P[id]);
                        }                 
					}                    
                    P[id][qI[id]] = '?';
                }
            }
        }
	}
}

int main() {
    cin >> N >> S;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> G[i];
        
        mp[P[i]].push_back(G[i]);
        
        if (P[i] == S) {
            cout << G[i] << "\n";
            return 0;
        }         
        
        if (func(S, P[i]) && mp[P[i]].size() == 10) {
            sort(mp[P[i]].rbegin(), mp[P[i]].rend());
            cout << mp[P[i]][0] << "\n";
            return 0;
        }
        
        bool has_q_tmp = false;
        
        for (int j = 0; j < (int) P[i].size(); j++) {
            if (P[i][j] == '?') {
                has_q_tmp = true;
                qI[i] = j;
            }
        }
        has_q[i] = has_q_tmp;
    }
     
    for (int i = 0; i < N; i++) {
        if (func(S, P[i]) && G[i] > ans) {
            memo.clear();   
            memo.insert(S);
            for (int j = 0; j < N; j++) {
                if (!has_q[j]) {
                    memo.insert(P[j]);
                }
            }
                     
			// cout << ans << "\n";
            rec(0, i);
        }   
    }
    
    cout << ans << "\n";
    
    return 0;
}
