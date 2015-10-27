#include <bits/stdc++.h>

using namespace std;

int T;
string N1, N2;

string toBin(string s) {
	unsigned int ans = 0;

	for (int i = 0; i < s.size(); i++) {
		int val = 0;

		if (s[i] >= '0' && s[i] <= '9') {
			val = s[i] - '0';
		} else {
			val = 10 + s[i] - 'A';
		}
		ans = ans * 16 + val;
	}

	string ans_s = "";

	while (ans > 0) {
		ans_s = char('0' + ans % 2) + ans_s;
		ans /= 2;
	}

	while (ans_s.size() < 32) {
		ans_s = "0" + ans_s;
	}

	return ans_s;
}

int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N1 >> N2;

		string A = toBin(N1);
		string B = toBin(N2);

		int bestR = INT_MAX;
		int bestL = INT_MAX;

		cout << "Case #" << t << ": ";

		string rotRA = A;
		string rotLA = A;
		//    cout << A << " " << B << "\n";
		for (int i = 0; i < (int) A.size(); i++) {
			//cout << rotRA << " " << rotLA << " " << B << "\n";
			if (rotRA == B) {
				bestR = min(bestR, i);
			}      
			if (rotLA == B) {
				bestL = min(bestL, i);
			}
			rotRA = rotRA.back() + rotRA;
			rotRA.erase(rotRA.end() - 1);

			rotLA = rotLA + rotLA.front();
			rotLA.erase(rotLA.begin());
		}    

		if (bestR == INT_MAX && bestL == INT_MAX) {
			cout << "Not possible\n";
		} else {
			if (bestR == bestL) {
				cout << bestL << " Any\n";
			} else {
				if (bestR < bestL) {
					cout << bestR << " Right\n";
				} else {
					cout << bestL << " Left\n";
				}
			}
		}
	}
	return 0;
}
