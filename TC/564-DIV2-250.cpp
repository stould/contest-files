#line 81 "FauxPalindromes.cpp"
/*
aajjbb
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

bool ok(string s) {
	int i;
	REP(i, s.size()) if(s[i] != s[s.size()-i-1]) return false;
	return true;
}

struct FauxPalindromes {
	string classifyIt(string word) {
		if(ok(word)) return "PALINDROME";
		int i;
		REP(i, word.size()) {
			int j = i+1;
			while(j < word.size() && word[i] == word[j]) {
				word.erase(word.begin()+j);
			}
		} 
		if(ok(word)) return "FAUX";
		return "NOT EVEN FAUX";
	}
};


// Powered by FileEdit
