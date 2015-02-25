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

string S, T;
int cnt[1024], seen[1024];

int get_oppo(char s) {
	if (s >= 'a' && s <= 'z') {
		return 'A' + (s - 'a');
	} else {
		return 'a' + (s - 'A');
	}
}

int main(void) {
	cin >> S >> T;

	int N = (int) S.size();
	int M = (int) T.size();

	int y = 0;
	int w = 0;

	for (int i = 0; i < M; i++) {
		cnt[T[i]] += 1;
	}

	for (int i = 0; i < N; i++) {
		seen[S[i]] += 1;
	}

	for (int i = 0; i < 1024; i++) {
		if (seen[i] > 0) {
			if (cnt[i] <= 0) continue;
			
			if (cnt[i] >= seen[i]) {
				y += seen[i];
				
				cnt[i] -= seen[i];
				seen[i] = 0;
			} else {
				y += cnt[i];

				seen[i] -= cnt[i];
				cnt[i] = 0;
			}
		}
	}

	for (int i = 0; i < 1024; i++) {
		if (seen[i] > 0) {
			int pos_oppo = get_oppo(i);

			if (cnt[pos_oppo] <= 0) continue;

			if (cnt[pos_oppo] >= seen[i]) {
				w += seen[i];
				
				cnt[pos_oppo] -= seen[i];
				seen[i] = 0;
			} else {
				w += cnt[pos_oppo];
				
				seen[i] -= cnt[pos_oppo];
				cnt[pos_oppo] = 0;
			}
		}
	}

	cout << y << " " << w << "\n";
		
    return 0;
}
