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

const double EPS = 1e-9;
double X, Y, Z;

double f1() {
	return (Z * log2(Y)) * log2(X);
}
double f2() {
	return (Y * log2(Z)) * log2(X);
}
double f3() {
	return Z * log2((Y * log2(X)));
}
double f4() {
	return Y * log2((Z * log2(X)));
}
double f5() {
	return (Z * log2(X)) * log2(Y);
}
double f6() {
	return (X * log2(Z)) * log2(Y);
}
double f7() {
	return Z * log2((X * log2(Y)));
}
double f8() {
	return X * log2((Z * log2(Y)));
}
double f9() {
	return (Y * log2(X)) * log2(Z);
}
double f10() {
	return (X * log2(Y)) * log2(Z);
}
double f11() {
	return Y * log2((X * log2(Z)));
}
double f12() {
	return X * log2((Y * log2(Z)));
}


int main(void) {
	cin >> X >> Y >> Z;

	X *= 5;
	Y *= 5;
	Z *= 5;

	double best = 1000000.0;
	string ans = "";

	vector<double> vd = {f1(), f2(), f3(), f4(), f5(), f6(), f7(), f8(), f9(), f10(), f11(), f12()};
	vector<string> vs = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y", "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x", "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};

	for (int i = 0; i < 12; i++) {
		cout << fixed << setprecision(15) << vs[i] << " " << vd[i] << "\n";
		if (best > vd[i]) {
			best = vd[i];
			ans = vs[i];
		}
	}

	cout << ans << "\n";

	return 0;
}
