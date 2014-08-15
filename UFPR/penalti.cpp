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

int N;
string A, B;

int main(void) {
	cin >> N >> A >> B;
	
	int sumA = 0, sumB = 0;
	int tot = 0, ans = -1;;

	for (int i = 0; i < N; i++) {
		if (A[i] == 'o') sumA += 1;
		tot += 1;
		if (sumB + N - i < sumA || sumA + N - i - 1 < sumB) {
			ans = tot;
			break;
		}
		if (B[i] == 'o') sumB += 1;
		tot += 1;
		if (sumA + N - i - 1 < sumB || sumB + N - i - 1 < sumA) {
			ans = tot;
			break;
		}
	}
	if (ans == -1 && sumA != sumB) {
		ans = 2 * N;
	}
	if (ans == -1) {
		cout << "Empate\n";
	} else {
		cout << ans << "\n";
	}
    return 0;
}
