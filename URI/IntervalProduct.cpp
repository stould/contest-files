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

template<typename T = int>
struct FenwickTree {
    int N;
    T *values;

    FenwickTree(int N) {
        this->N = N;
        values = new T[N+5];

        for(int i = 1; i <= N; i++) values[i] = 0;
    }

	void increase(int index, T add) {
        while(index <= N) {
            values[index] += add;
            index += (index & -index);
        }
    }


    void update(int index, T new_value) {
        increase(index, new_value - readSingle(index));
    }

    T read(int index) {
        T sum = 0;

        while(index > 0) {
            sum += values[index];
            index -= (index & -index);
        }

        return sum;
    }

    T readSingle(int index){
        T sum = values[index];
        if(index > 0) {
            int z = index - (index & -index);
            index--;
            while(index != z) {
                sum -= values[index];
                index -= (index & -index);
            }
        }
        return sum;
    }

    T read(int low, int high) {
        return read(high) - read(low - 1);
    }
};

const int MAXN = 100005;

int N, K;
int P[MAXN];

int sign(int x) {
	if (x < 0) {
		return -1;
	} else if (x > 0) {
		return 1;
	} else {
		return 0;
	}
}

int main(void) {
	while (cin >> N >> K) {
		FenwickTree<int> zero(N), minus(N);
		
		for (int i = 1; i <= N; i++) {
			cin >> P[i];

			if (sign(P[i]) == 0) {
				zero.update(i, 1);
			} else if (sign(P[i]) < 0) {
				minus.update(i, 1);
			}
		}
		int I, V;
		char C;
		
		for (int i = 0; i < K; i++) {
			cin >> C >> I >> V;
			
			if (C == 'C') {
				if (V == 0) {
					zero.update(I, 1);
					minus.update(I, 0);
				} else if (V < 0) {
					zero.update(I, 0);
					minus.update(I, 1);
				} else {
					zero.update(I, 0);
					minus.update(I, 0);
				}
			} else {
				int z = zero.read(I, V);
				int m = minus.read(I, V);

				
				if (z > 0) {
					cout << "0";
				} else if (m % 2 == 0) {
					cout << "+";
				} else {
					cout << "-";
				}
			}
		}
		cout << endl;
	}
	return 0;
}
