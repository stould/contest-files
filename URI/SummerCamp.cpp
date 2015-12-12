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

int N;
string S[110];
int P[110];

int main(void) {
	while (cin >> N && N != 0) {
		vector<pair<int, int> > vs;
		
		for (int i = 0; i < N; i++) {
			cin >> S[i] >> P[i];

			vs.push_back(make_pair(i, P[i]));
		}
		
		int curr = 0, len = vs[0].second;
		
		for (int x = 0; x < N - 1; x++) {
			int next = vs[curr].first;

			if (len % 2 == 1) {
				next += len;
				next %= (N - x);
			} else {
				next -= len;
				next %= (N - x);
				next += (N - x);
				next %= (N - x);
			}

			curr = vs[next].first;
			len = vs[next].second;

			vs.erase(vs.begin() + next);

			//next -= 1;
			
			//next %= (N - x - 1);
			//			next += (N - x - 1);
			//next %= (N - x - 1);
		}

		cout << "Vencedor(a): " << S[vs[0].first] << "\n";
	}
	return 0;
}
