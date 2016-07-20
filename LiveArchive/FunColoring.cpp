#include <bits/stdc++.h>

using namespace std;

const int MAXN = 115;

int T, N, M;
string S;
bitset<MAXN> bi[MAXN];
int main() {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
    
        for (int i = 0; i < MAXN; i++) {
            bi[i].reset();
        }

        getline(cin, S);

        for (int i = 0; i < M; i++) {
            getline(cin, S);
            
            int a = -1, b = -1, c = -1;
            sscanf(S.c_str(), "%d%d%d", &a, &b, &c);
      
            a -= 1;
            b -= 1;
            c -= 1;
            //cout << a << " " << b << " " << c << endl;
            if (a >= 0) {
                bi[i].set(a);
            }
            if (b >= 0) {
                bi[i].set(b);
            }
            if (c >= 0) {
                bi[i].set(c);
            }
        }

        bool ans = false;

        for (int i = 0; i < (1 << N); i++) {
            bool fine = true;
            
            for (int j = 0; j < M; j++) {
                int a = 0;
                int b = 0;

                if (bi[j].count() >= 2) {
                    for (int k = 0; k < N; k++) {
                        if (bi[j].test(k)) {
                            if (i & (1 << k)) {
                                a += 1;
                            } else {
                                b += 1;
                            }
                        }
                    }
                    //cout << a << " " << b << endl;
                    if (a == 0 or b == 0) {
                        fine = false;
                        break;
                    }
                }                
            }
            if (fine) {
                ans = true;
                break;
            }
        }
        if (ans) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
    //cout << "\n";
    return 0;
}
