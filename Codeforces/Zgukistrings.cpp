#include <bits/stdc++.h>

using namespace std;

const int MAX_C = 26;
const int INF = INT_MAX / 8;

string A, B, C;
vector<int> cnt(MAX_C);
int bcnt[30], ccnt[30];

int func(int already) {
	int ans = INF;

	for (int i = 0; i < MAX_C; i++) {    
		int acurr = cnt[i] - bcnt[i] * already;
    
		if (acurr < 0) return -1;

		if (ccnt[i] != 0) {      
			ans = min(ans, acurr / ccnt[i]);          
		}
	}
	return ans;
}
int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> A >> B >> C;
  
	for (int i = 0; i < (int) A.size(); i++) {
		cnt[A[i] - 'a'] += 1;
	}
	for (int i = 0; i < (int) B.size(); i++) {
		bcnt[B[i] - 'a'] += 1;
	}
	for (int i = 0; i < (int) C.size(); i++) {
		ccnt[C[i] - 'a'] += 1;
	}
  
	string ans = "";
	int cnt_b = 0;
	int cnt_c = 0;

	for (int i = 0; i <= A.size() / B.size(); i++) {
		int check = func(i);

		if (check == -1) continue;
    
		if (cnt_b + cnt_c < i + check) {      
			cnt_b = i;
			cnt_c = check;
		}
	}
  
	for (int i = 0; i < cnt_b; i++) {
		ans += B;
	}      
	for (int i = 0; i < cnt_c; i++) {
		ans += C;
	}
	for (int i = 0; i < MAX_C; i++) {
		cnt[i] -= cnt_b * bcnt[i];
		cnt[i] -= cnt_c * ccnt[i];
	}
	for (int i = 0; i < MAX_C; i++) {
		while (cnt[i] > 0) {
			ans += char('a' + i);
			cnt[i] -= 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
