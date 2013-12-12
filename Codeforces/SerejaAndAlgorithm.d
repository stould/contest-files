import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

//	Input
string[] tokens;
int tokenId = 0;
string readToken() { for (; tokenId == tokens.length; ) tokens = readln.split, tokenId = 0; return tokens[tokenId++]; }

int readInt() { return to!int(readToken); }
long readLong() { return to!long(readToken); }
real readReal() { return to!real(readToken); }

//	chmin/chmax
void chmin(T)(ref T t, T f) { if (t > f) t = f; }
void chmax(T)(ref T t, T f) { if (t < f) t = f; }

immutable int MAXN = 100005;

int M;
string S;

int[100005][5] dp;

void main () {
	S = readToken();
	M = readInt();

	int A, B;

	foreach(int i; 0 .. to!int(S.length)) {
		dp[to!int(S[i] - 'x')][i + 1] += 1;

		foreach(int j; 0 .. 3) {
			dp[j][i +	 1] += dp[j][i];
		}
	}

	foreach (int i; 0 .. M) {
		A = readInt();
		B = readInt();

		if (B - A < 2) {
			writeln("YES");
		} else {
			int[3] buff;

			foreach(int j; 0 .. 3) {				
				buff[j] = dp[j][B] - dp[j][A - 1];
			}

			buff.sort;

			if (buff[2] <= buff[0] + 1) {
				writeln("YES");
			} else {
				writeln("NO");
			}
		}
	}
}