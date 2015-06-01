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

string S;

bool isletter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(void) {
	set<string> dict;

	while (getline(cin, S)) {
		int N = (int) S.size();
		string buff = "";
		
		for (int i = 0; i < N; i++) {
			if (isletter(S[i])) {
				buff += S[i];
			} else {
				if (!buff.empty()) {
					transform(buff.begin(), buff.end(), buff.begin(), ::tolower);
					dict.insert(buff);
				} 
				buff = "";
			}
		}
		if (!buff.empty()) {
			transform(buff.begin(), buff.end(), buff.begin(), ::tolower);
			dict.insert(buff);			
		}
	}

	for (string curr: dict)  {
		cout << curr << "\n";
	}
	return 0;
}
