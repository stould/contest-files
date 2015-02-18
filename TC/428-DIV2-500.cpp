#include <bits/stdc++.h>

using namespace std;

class TheLuckyString {
public:
	int count(string);
};

int TheLuckyString::count(string s) {
	int ans = 0;
	int N = s.size();
	
	sort(s.begin(), s.end());
	
	do {
		bool ok = true;
		
		for (int i = 0; ok && i < N - 1; i++) {
			if (s[i] == s[i + 1]) ok = false;
		}
		if (ok) ans += 1;
	} while (next_permutation(s.begin(), s.end()));
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
