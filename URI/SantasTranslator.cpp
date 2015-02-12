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
map<string, string> tr;

void build(void) {
	tr["brasil"]          = "Feliz Natal!";
	tr["alemanha"]        = "Frohliche Weihnachten!";
	tr["austria"]         = "Frohe Weihnacht!";
	tr["coreia"]          = "Chuk Sung Tan!";
	tr["espanha"]         = "Feliz Navidad!";
	tr["grecia"]          = "Kala Christougena!";
	tr["estados-unidos"]  = "Merry Christmas!";
	tr["inglaterra"]      = "Merry Christmas!";
	tr["australia"]       = "Merry Christmas!";
	tr["portugal"]        = "Feliz Natal!";
	tr["suecia"]          = "God Jul!";
	tr["turquia"]         = "Mutlu Noeller";
	tr["argentina"]       = "Feliz Navidad!";
	tr["chile"]           = "Feliz Navidad!";
	tr["mexico"]          = "Feliz Navidad!";
	tr["antardida"]       = "Merry Christmas!";
	tr["canada"]          = "Merry Christmas!";
	tr["irlanda"]         = "Nollaig Shona Dhuit!";
	tr["belgica"]         = "Zalig Kerstfeest!";
	tr["italia"]          = "Buon Natale!";
	tr["libia"]           = "Buon Natale!";
	tr["siria"]           = "Milad Mubarak!";
	tr["marrocos"]        = "Milad Mubarak!";
	tr["japao"]           = "Merii Kurisumasu!";
}

int main(void) {
	build();
	for ( ; cin >> S; ) {
		if (tr[S] == "") {
			cout << "--- NOT FOUND ---\n";
		} else {
			cout << tr[S] << "\n";
		}
	}
    return 0;
}
