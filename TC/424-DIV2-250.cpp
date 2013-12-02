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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class MagicSpell {
public:
	string fixTheSpell(string);
};

string MagicSpell::fixTheSpell(string spell) {
	int i;
	int id = 0;
	int N = (int) spell.size();
	vector<char> bf;
	
	for (i = 0; i < N; i++) {
		if (spell[i] == 'A' || spell[i] == 'Z') {
			bf.push_back(spell[i]);
		}
	}	
	
	reverse(bf.begin(), bf.end());
	
	for (i = 0; i < N; i++) {
		if (spell[i] == 'A' || spell[i] == 'Z') {
			spell[i] = bf[id++];
		}
	}
	
	return spell;
}

//Powered by [KawigiEdit] 2.0!