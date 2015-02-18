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

int pos;
map<string, int> id;
map<int, int> prev, next;

void print(vector<int> s) {
	for (int i= 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << "\n";
}

void func(string s) {
	if (id[s] == 0) {
		id[s] = pos++;
	}
}

vector<int> pathA(int S, int E) {
	vector<int> ans;
	while (S != E) {
		ans.push_back(S);
		if (S == next[S]) break;
		S = next[S];
	}
	if (S == E) ans.push_back(E);
	return ans;
}

vector<int> pathB(int S, int E) {
	vector<int> ans;
	while (S != E) {
		ans.push_back(S);
		if (S == prev[S]) break;
		S = prev[S];
	}
	if (S == E) ans.push_back(E);
	return ans;
}

int main(void) {
	string A, B, C;
	int cnt = 0, S, E;
	pos = 1;
	bool ok = true;
	for ( ; cin >> A >> B >> C; ) {
		func(A);
		func(B);
		func(C);

		if (cnt == 0) {
			S = id[A];
		} else if (cnt == 1) {
			E = id[A];
		}
		if (prev[id[A]] == 0 || prev[id[A]] == id[B]) {
			prev[id[A]] = id[B];
		} else {
			ok = false;
		}
		if (B != "0" && next[id[B]] == 0 || next[id[B]] == id[A]) {
			next[id[B]] = id[A];
		} else {
			ok = false;
		}
		if (next[id[A]] == 0 || next[id[A]] == id[C]) {
			next[id[A]] = id[C];
		} else {
			ok = false;
		}

		if (C != "0" && prev[id[C]] == 0 || prev[id[C]] == id[A]) {
			prev[id[C]] = id[A];
		} else {
			ok = false;
		}
		cnt++;
	} 
	vector<int> pa = pathA(S, E), pb = pathB(E, S);
	reverse(pb.begin(), pb.end());

	if (ok && S == E || (!pa.empty() && pa == pb)) {
		cout << "sana\n";
	} else {
		cout << "insana\n";
	}
    return 0;
}
