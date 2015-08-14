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
typedef unsigned uint;

const int MAXN = 300005;

int N, M;
string S;
int tree[MAXN];
void increase(int index, int add) {
	while (index <= N) {
            tree[index] += add;
            index += (index & -index);
        }
    }

	void decrease(int index, int add) {
        while(index <= N) {
            tree[index] -= add;
            index += (index & -index);
        }
    }


int read(int index) {
	int sum = 0;

        while(index > 0) {
            sum += tree[index];
            index -= (index & -index);
        }

        return sum;
    }
int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> S;

	S = 'a' + S + 'z';

	N += 2;

	set<int> val_pos;
	set<int>::iterator it;
	
	for (int i = 0; i < N; i++) {
		if (S[i] == '.') {
			increase(i, 1);
		}
		if (i > 0 && S[i] != '.' && S[i - 1] == '.') {
			val_pos.insert(i);
		}
	}

	for (int i = 0; i < M; i++) {
		int pos;
		char value;
		
		cin >> pos >> value;

		if (S[pos] == '.' && value != '.') {
			decrease(pos, 1);

			if (pos - 1 >= 0 && S[pos - 1] == '.') {
				val_pos.insert(pos);
			}
			if (val_pos.count(pos + 1)) {
				val_pos.erase(pos + 1);
			}
		} else if (S[pos] != '.' && value == '.') {
			increase(pos, 1);

			if (pos - 1 >= 0 && S[pos - 1] == '.') {
				val_pos.erase(pos);
			}
			if (pos + 1 < N && S[pos + 1] != '.') {
				val_pos.insert(pos + 1);
			}
		}

		S[pos] = value;

		int ans = 0, seen = 0;
		
		for (it = val_pos.begin(); it != val_pos.end(); it++) {
			int now = read(*it);
			
			ans += max(0, now - seen - 1);
			seen += now;
		}
		cout << ans << "\n";
	}
	return 0;
}
