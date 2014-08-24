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

const int MAXN = 60;

int T, L, C;
string SL[MAXN], SC[MAXN];

int func(string S, string K) {
    vector<int> T(K.size() + 1, -1);
	int ans = 0;

    if(K.size() == 0) {
		return 0;
    }

    for(int i = 1; i <= K.size(); i++) {
        int pos = T[i - 1];
        while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }

    int sp = 0;
    int kp = 0;
    while(sp < S.size()) {
        while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
        kp++;
        sp++;
        if(kp == K.size()) ans += 1;
    }

    return ans;
}


int main(void) {
	cin >> T;
	for ( ; T--; ) {
		cin >> L >> C;

		char b;

		for (int i = 0; i < MAXN; i++) SL[i] = SC[i] = "";

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < C; j++) {
				cin >> b;
				SL[i] += b;
				SC[j] += b;
			}
		}

		string PT;
		int P;

		cin >> P;

		for ( ; P--; ) {
			cin >> PT;

			int ans = 0;
			
			for (int i = 0; i < L; i++) {
				ans += func(SL[i], PT);
			}
			for (int i = 0; i < C; i++) {
				ans += func(SC[i], PT);
			}
			
			if (PT.size() == 1) ans /= 2;

			cout << ans << "\n";
		}
	}
    return 0;
}
