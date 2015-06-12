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

const int MAXN = 220;

int T, N;
string E, F, S[MAXN];
set<string> sE, sF;

vector<string> split(string s) {
	istringstream ss(s);
	string buff;

	vector<string> ans;
	
	while (ss >> buff) {
		ans.push_back(buff);
	}
	
	return ans;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		
		getline(cin, E);
		getline(cin, F);

		set<string> amb;

		vector<string> senE = split(E);
		vector<string> senF = split(E);

		for (int i = 0; i < (int) senE.size(); i++) {
			if (find(senF.begin(), senF.end(), senE[i]) != senF.end()) {
				amb.insert(senE[i]);
			}
		}

		for (int i = 0; i < (int) senF.size(); i++) {
			if (find(senE.begin(), senE.end(), senF[i]) != senE.end()) {
				amb.insert(senF[i]);
			}
		}				
		
		for (int i = 0; i < N - 2; i++) {
			getline(cin, S[i]);
		}

		sE = set<string>(senE.begin(), senE.end());
		sF = set<string>(senF.begin(), senF.end());
		
	}
	return 0;
}
