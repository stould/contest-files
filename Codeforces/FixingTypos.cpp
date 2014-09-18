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

const int MAXN = 2000005;

int N;
string S;
string dp[MAXN];
bool mark[MAXN];

bool cmp(string a, string b) {
	return a.size() < b.size();
}

string func(int id) {
	if (id >= N) {
		return "";
	} else {
		if (!mark[id]) {
			mark[id] = true;		
			
			dp[id] = "";

			vector<string> vs;


			int cont = 0;
			for (int i = 0; i < 3 && id + i < N; i++) {
				if (S[id] == S[id + i]) {
					cont += 1;
				}
			}
			if (cont == 3) {
				string t = string(1, S[id]) + string(1, S[id + 1]) + func(id + 3);
				vs.push_back(t);
			}
			
			cont = 0;
			for (int i = 0; i < 4 && id + i < N; i++) {
				if (i <= 1) {
					if (S[id] == S[id + i]) {
						cont += 1;
					}
				} else {
					if (S[id + i] == S[id]) cont = -10;
					if (S[id + 2] == S[id + i]) {
						cont += 1;
					}
				}
			}
			if (cont == 4) {
				string t = string(1, S[id]) + string(1, S[id + 1]) + string(1, S[id + 2]) + func(id + 4);
				vs.push_back(t);

			}
			vs.push_back(S[id] + func(id + 1));

			sort(vs.begin(), vs.end(), cmp);
			
			dp[id] = vs[0];			
		 }

		 return dp[id];
	 }
 }

 int main(void) {
	 cin >> S;
	 N = (int) S.size();
	 
	 string ans = "";

	 for (int i = 0; i < N; i++) {
		 ans += S[i];
		 
		 if (i + 1 < N) {
			 int j = i + 2;
			 while (j < N && S[i] == S[j]) {
				 
			 }
		 }
	 }

	 cout << ans << "\n";

	 return 0;
 }
