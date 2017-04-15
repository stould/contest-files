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

int T, N, M;
string S[30];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }

        set<char> used;
        
        while (1) {
            int best = 0;

            int ai = -1;
            int aj = -1;
            int ak = -1;
            int al = -1;
            
            char chr = '?';
            
            bool fine = false;
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    for (int k = i; k < N; k++) {
                        for (int l = j; l < M; l++) {
                            int all = 0;
                            int dub = 0;
                            char curr_char = '?';
                            
                            for (int a = i; a <= k; a++) {
                                for (int b = j; b <= l; b++) {
                                    all += 1;
                                    if (S[a][b] == '?') {
                                        dub += 1;
                                    } else {
                                        curr_char = S[a][b];
                                    }
                                }
                            }
                            if (all - dub == 1 && dub > 0 && !used.count(curr_char)) {
                                fine = true;

                                if (all > best) {
                                    best = all;
                                    ai = i;
                                    aj = j;
                                    ak = k;
                                    al = l;
                                    
                                    chr = curr_char;
                                }
                            }
                        }
                    }
                }
            }
            if (!fine) break;

            used.insert(chr);
            
            for (int i = ai; i <= ak; i++) {
                for (int j = aj; j <= al; j++) {
                    S[i][j] = chr;
                }
            }
        }
        cout << "Case #" << t << ":\n";

        for (int i = 0; i < N; i++) {
            cout << S[i] << "\n";
        }
    }
    
    return 0;
}
