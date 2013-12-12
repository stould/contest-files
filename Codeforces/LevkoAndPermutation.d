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

int N;
int K;

void main () {
     N = readInt();
     K = readInt();

     int i;

     if (N == K) {
     	writeln("-1");
     } else if (N == K + 1) {
     	for (i = 1; i <= N; i++) {
     		writef("%s ", i);
     	}
     } else {     
     	writef("%s ", N);

     	for (i = 2; i <= K + 1; i++) {
     		writef("%s ", i);
     	}
     	
     	writef("%s ", 1);

     	for (i = K + 2; i <= N - 1; i++) {
     		writef("%s ", i);
     	}
     }
}