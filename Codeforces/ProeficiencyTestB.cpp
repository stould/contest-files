#include <bits/stdc++.h>

using namespace std;

string T, S[110], G[110];
int N;

bool right(int id, vector<int> pos) {
    int w = 0;
    
    for (int i = 0; i < (int) pos.size(); i++) {    
        if (S[id][pos[i]] != T[pos[i]]) w += 1;
    }
    if (w >= 3) {
        return false;
    }
    return true;
}

int main() {
    cin >> T >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> G[i];
    }
    
    int r = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 8; j < 16; j++) {
            for (int k = 16; k < 24; k++) {
                for (int l = 24; l < 32; l++) {
                    for (int m = 32; m < 40; m++) {
                        for (int n = 40; n < 48; n++) {
                            bool ok = true;
                            
                            vector<int> pos;
                            pos.push_back(i);     
                            pos.push_back(j);
                            pos.push_back(k);
                            pos.push_back(l);
                            pos.push_back(m);
                            pos.push_back(n);
                            
                            for (int a = 0; a < N; a++) {
                                if (right(a, pos)) {
                                    if (G[a] == "-") {
                                        ok = false;
                                    }
                                } else {
                                    if (G[a] == "+") {
                                        ok = false;
                                    }
                                }
                            }
                            
                            if (ok) r += 1;   
                        }
                    }
                }
            }
        }
    }
    
    if (r == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
