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

int main(void) {
	cin >> N;

	vector<uInt> od; 
	
	uInt all = 0;

	for (int i = 0; i < N; i++) {
		uInt A;
		cin >> A;

		if (A % 2 == 0) {
			all += A;
		} else{
			od.push_back(A);
		}
	}
	
	sort(od.rbegin(), od.rend());

	int s = od.size() % 2 == 0 ? od.size() : od.size() - 1;
	
	for (int i = 0; i < s; i++) {
		all += od[i];
	}

	cout << all << "\n";
	
	return 0;
}
