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

string S, A, B;

bool isSep(char c) {
	return c == ',' || c == ';';
}

bool isNum(string arg) {
	if (arg.empty() || arg.find('.') != string::npos) return false;

	if (arg[0] == '0') {
		return arg.size() == 1;
	}
	
	for (int i = 0; i < (int) arg.size(); i++) {
		if (!(arg[i] >= '0' && arg[i] <= '9')) {
			return false;
		}
	}
	
	return true;
}

int main(void) {
	cin >> S;

	int N = (int) S.size();

	vector<string> va, vb;
	
	for (int i = 0; i < N; i++) {
		if (!isSep(S[i])) {
			string buff = "";

			int j = i;

			while (j < N && !isSep(S[j])) {
				buff += S[j];
				j += 1;
			}

			if (isNum(buff)) {
				va.push_back(buff);
			} else {
				vb.push_back(buff);
			}
			
			i = j - 1;
		} else {
			if (i + 1 < N && isSep(S[i + 1])) {
				vb.push_back("");
			}
			if (i == 0) {
				vb.push_back("");
			}
			if (i == N - 1) {
				vb.push_back("");
			}			
		}
	}

	for (int i = 0; i < (int) va.size(); i++) {
		A += va[i];
		if (i != (int) va.size() - 1) {
			A += ",";
		}
	}

	for (int i = 0; i < (int) vb.size(); i++) {
		B += vb[i];
		if (i != (int) vb.size() - 1) {
			B += ",";
		}
	}
		

	if (va.empty()) {
		A = "-";
	} else {	
		A = "\"" + A + "\"";
	}
	if (vb.empty()) {
		B = "-";
	} else {
		B = "\"" + B + "\"";
	}

	cout << A << "\n" << B << "\n";
	
	return 0;
}
