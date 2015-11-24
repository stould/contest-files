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

string S;

vector<int> split(string& arg) {
	vector<int> ans;
	istringstream ss(arg);
	int buff;

	while (ss >> buff) {
		ans.push_back(buff);
	}
	
	return ans;
}

bool sorted(vector<int> arg) {
	for (int i = 1; i < (int) arg.size(); i++) {
		if (arg[i] < arg[i - 1]) return false;
	}
	return true;
}

void test() {
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 30; j++) {
			if (j > 0) cout << " ";
			cout << rand() % 100;
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(void) {
	//test();
	//return 0;
	while (getline(cin, S)) {
		vector<int> st = split(S);
		vector<int> backup = st;
		vector<int> ans;

		if (st.empty()) break;
		
		bool init = sorted(st);
		
		for (int x = 0; x < (int) st.size(); x++) {
			if (sorted(st)) break;
			
			int curr = INT_MIN;
			for (int i = x; i < (int) st.size(); i++) {
				curr = max(curr, st[i]);
			}
			
			if (st[x] != curr) {
				for (int i = x; i < (int) st.size(); i++) {
					if (st[i] == curr) {
						if (i != (int) st.size() - 1) {
							ans.push_back(i + 1);
							reverse(st.begin() + i, st.end());
						}
						ans.push_back(x + 1);
						reverse(st.begin() + x, st.end());					
						break;						
					}
				}
			}
		}
		
		if (!sorted(st)) {
			ans.push_back(1);
			reverse(st.begin(), st.end());
		}

		//if (!sorted(st)) cout << "ZZZZzzzZZzzZ";
		
		ans.push_back(0);
				
		for (int i = 0; i < (int) backup.size(); i++) {
			if (i > 0) {
				cout << " ";
			}
			cout << backup[i];
		}
		cout << "\n";

		for (int i = 0; i < (int) ans.size(); i++) {
			if (i > 0) {
				cout << " ";
			}
			cout << ans[i];
		}
		cout << "\n";
	}
	return 0;
}
