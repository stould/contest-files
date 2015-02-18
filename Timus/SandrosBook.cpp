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

int KMP(string S, string K) {
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
        while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) {
			kp = T[kp];
		}
        kp++;
        sp++;
        if(kp == K.size()) {
			ans += 1;
		}
    }

    return ans;
}

string S;

int main(void) {
	cin >> S;
	string ans = "";
	int N = (int) S.size();
	int ans_cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N - i; j++) {
			string curr = S.substr(i, j);
			int tmp = KMP(S, curr);

			if (tmp > ans_cnt || (tmp == ans_cnt && curr.size() > ans.size())) {
				ans_cnt = tmp;
				ans = curr;
			}
			
		}
	}
	

	cout << ans << "\n";
    return 0;
}

