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

int A, B, C;

void main () {
	A = readInt();
	B = readInt();
	C = readInt();

	bool ok = false;

	foreach(int X; 0 .. A + 1) {
		int Y = B - X;
		int Z = C - Y;

		if (Y < 0 || Z < 0) continue;

		if (X + Y == B && X + Z == A && Y + Z == C) {
			writefln("%s %s %s", X, Y, Z);
			ok = true;
			break;
		}
	}

	if (!ok) {
		writeln("Impossible");
	}
}