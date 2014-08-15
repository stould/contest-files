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

const int TAPE_S = 30000;
const int MAX_S = 100003;
int T, N, M;
int p, spos;
char S[MAX_S], F[MAX_S];
char tape[TAPE_S];

void process(string str) {
	int SL = (int) str.size();
	for (int i = 0; i < SL; i++) {
		char curr = str[i];

		if (curr == '>') {
			p = (p + 1) % TAPE_S;
		} else if (curr == '<') {
			p = (p - 1 + TAPE_S) % TAPE_S;
		} else if (curr == '+') {
			tape[p] += 1;
		} else if (curr == '-') {
			tape[p] -= 1;
		} else if (curr == '.') {
			cout << tape[p];
		} else if (curr == '#') {
			for (int j = 0; j < 10; j++) {
				cout << tape[j];
			}
		} else if (curr == ',') {
			if (spos < M) {
				tape[p] = S[spos++];						
			} else {
				tape[p] = 0;
			}
		} else if (curr == '[') {
			int j = i, len = 0;
			deque<char> stack;

			while (j < SL) {
				len += 1;
				if (str[j] == '[') {
					stack.push_back('[');
				} else if (str[j] == ']') {
					stack.pop_back();
					if (stack.empty()) {
						j++;
						break;
					}
				}
				j += 1;
			}
			string inner_loop = str.substr(i + 1, j - i - 2);
			while (tape[p] != 0) {
				process(inner_loop);
				if (tape[p] == 0) break;
			}
			i = j - 1;
		}
	}
}

int main(void) {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%s%s", S, F);
		
		N = strlen(F);
		M = strlen(S);

		p = 0;
		spos = 0;

		memset(tape, 0, sizeof(tape));
		printf("Instancia %d\n", t);

		process(F);
		
		printf("\n\n");
	}

    return 0;
}
