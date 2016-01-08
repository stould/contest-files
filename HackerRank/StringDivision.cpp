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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int T;
string S;

int main(void) {
	cin >> T;

	while (T--) {
		cin >> S;

		int N = (int) S.size();

		if (N < 4) {
			cout << "NO\n";
		} else if (N >= 10) {
			cout << "YES\n";
		} else {
			bool ok = false;
			
			for (int i = 1; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					for (int k = j + 1; k < N; k++) {
						string a = S.substr(0, i);
						string b = S.substr(i, j - i);
						string c = S.substr(j, k - j);
						string d = S.substr(k, N - k);

						set<string> st;

						st.insert(a);
						st.insert(b);
						st.insert(c);
						st.insert(d);

						if (st.size() == 4) {
							ok = true;
							goto end;
						}
					}
				}
			}
		end:;
			if (ok) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}
