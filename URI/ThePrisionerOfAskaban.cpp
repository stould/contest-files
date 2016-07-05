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
string flip;
string S[10];
int P[10];

string val = "4567QJKA23";
string tru = "DSHC";

int value(string card) {
	int ans = 0;
	int pos = val.find(flip[0]);

	ans += val.find(card[0]);
	
	if (card[0] == val[(pos + 1) % (int) val.size()]) {
		ans += 10 * tru.find(card[1]);
	}
	
	return ans;
}

int main(void) {
	cin >> N >> flip;

	for (int i = 0; i < 4; i++) {
		cin >> S[i] >> P[i];
	}

	vector<int> points(4);

	for (int i = 0; i < N; i++) {
		string card;
		vector<pair<int, int> > check;
		
		for (int j = 0; j < 4; j++) {
			cin >> card;			
			check.push_back(make_pair(value(card), j));
		}

		sort(check.rbegin(), check.rend());

		if (check[0].first != check[1].first) {
			points[check[0].second] += 1;
		}
	}
	
	int best = INT_MAX, cnt = 0;
	int ans = -1;
	
	for (int i = 0; i < 4; i++) {
		int curr = abs(P[i] - points[i]);
		if (curr < best) {
			best = curr;
			ans = i;
			cnt = 1;
		} else if (curr == best) {
			cnt += 1;
		}
	}

	if (cnt == 1) {
		cout << S[ans] << endl;
	} else {
		cout << "*" << endl;
	}
	return 0;	
}
