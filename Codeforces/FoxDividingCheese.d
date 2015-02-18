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

int A, B;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int func(ref int x) {
    int ans = 0;

    for ( ; x % 2 == 0; ) {
        x /= 2;
        ans += 1;
    }
    for ( ; x % 3 == 0; ) {
        x /= 3;
        ans += 1;
    }
    for ( ; x % 5 == 0; ) {
        x /= 5;
        ans += 1;
    }

    if (x != 1) ans = -1;

    return ans;
}

void main () {
    A = readInt();
    B = readInt();

    int d = gcd(A, B);

    A /= d;
    B /= d;

    int cx = func(A);
    int cy = func(B);

    int ans = cx + cy;

    if (cx == -1 || cy == -1) ans = -1;

    writeln(ans);
}
