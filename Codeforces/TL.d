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

void main () {
    int N; N = readInt();
    int M; M = readInt();

    int[110] valid;
    int[110] invalid;

    int best = 0;

    foreach (i; 0 .. N) {
        valid[i] = readInt();
        chmax(best, valid[i]);
    }

    foreach (i; 0 .. M) {
        invalid[i] = readInt();
        chmax(best, invalid[i]);
    }

    bool ok = false;

    foreach (i; 1 .. best + 1) {
        bool les = true;
        bool exe = false;
        bool big = true;

        foreach (j; 0 .. N) {
            if (valid[j] > i) {
                les = false;
            }
            if (valid[j] * 2 <= i) {
                exe = true;
            }
        }

        foreach (j; 0 .. M) {
            if (invalid[j] <= i) {
                big = false;
            }
        }   

        if (exe && les && big) {
            ok = true;
            writeln("", i);
            break;
        }
    }
    
    if (!ok) {
        writeln("-1");
    }
}
