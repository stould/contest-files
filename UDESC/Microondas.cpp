#include <bits/stdc++.h>

using namespace std;

int T, M, S, P;

string inToS(int s) {
	string ans = "";

	while(s > 0) {
		ans = char('0' + (s % 10)) + ans;
		s /= 10;
	}

	return ans;
}

pair<int, int> toR(int s) {
	return make_pair((s / 60) % 60, s % 60);
}

pair<int, string> cost(pair<int, int> as) {
	string asS = inToS(as.first) + inToS(as.second);

	if (as.second == 0) {
		asS = asS + "00";
	} else if (as.second < 10) {
		asS = asS + "0";
	}

	char last = '-';
	int ans = 0;
  
	for (int i = 0; i < (int) asS.size(); i++) {
		if (i > 0 && asS[i] != last) {
			ans += 1;
		}
		last = asS[i];
	}
	//cout << asS << " " << ans + (int) asS.size() << "\n";
	return make_pair(ans + (int) asS.size(), asS);
}

int main(void) {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d:%d", &M, &S);
		scanf("%d", &P);
    
		int inS = S + M * 60; 
		int R = P * inS / 100;

		int best = INT_MAX;
		string ans = "";

		for (int i = 0; i <= R; i++) {
			int now = inS + i;
			pair<int, int> curr;
      
			curr = toR(now);
      
			while (1) {
				if (curr.first < 0 || curr.second >= 100) break;
		
				int nowCost = cost(curr).first;
				string rep = cost(curr).second;
	
				if (best > nowCost) {
					best = nowCost;
					ans = rep;
				} 
	
				curr.first -= 1;
				curr.second += 60;
			}

			now = inS - i;
      
			curr = toR(now);
      
			while (1) {
				if (curr.first < 0 || curr.second >= 100) break;
		
				int nowCost = cost(curr).first;
				string rep = cost(curr).second;
	
				if (best > nowCost) {
					best = nowCost;
					ans = rep;
				} 
	
				curr.first -= 1;
				curr.second += 60;
			}      
		}    
    
		cout << "CASO #" << t << ": ";
		cout << ans << "\n";
	}
	return 0;
}
