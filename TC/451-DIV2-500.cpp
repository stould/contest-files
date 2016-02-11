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

class BoredPhilosophers {
public:
	vector <int> simulate(vector <string>, int);
};

vector<string> split(string& arg) {
	istringstream ss(arg);
	string buff;
	vector<string> ans;
	
	while (ss >> buff) {
		ans.push_back(buff);
	}
	
	return ans;
}

vector <int> BoredPhilosophers::simulate(vector <string> text, int N) {
	string all = accumulate(text.begin(), text.end(), string(""));
	
	vector<string> words = split(all);
	
	vector<int> ans(N);
	
	for (int i = 0; i < N; i++) {
		set<list<string> > st;				
		list<string> curr;
		
		for (int j = 0; j < (int) words.size(); j++) {
			curr.push_back(words[j]);
			
			if (j >= i) {
				if (j >= i + 1) {
					curr.pop_front();		
				}
				
				st.insert(curr);
			}
		}
		
		ans[i] = (int) st.size();
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
