#include <bits/stdc++.h>

using namespace std;

class FindingSquareInTable {
public:
	int findMaximalSquare(vector <string>);
};

int FindingSquareInTable::findMaximalSquare(vector <string> table) {
	int N = (int) table.size();
	int M = (int) table[0].size();
	
	int ans = -1;
	
	set<long long> perf;	
	
	for (long long i = 0LL; i * i < 100000000000LL; i++) {
		perf.insert(i * i);
	}
	
	for (int i = 0; i < N; i++) {
		for (int row_rate = -N; row_rate <= N; row_rate++) {			
			for (int j = 0; j < M; j++) {
				for (int col_rate = -M; col_rate <= M; col_rate++) {		
					if (row_rate == 0 && col_rate == 0) continue;	
					long long f = 0LL;				
					
					int pi = i;
					int pj = j;
					
					while (pi >= 0 && pj >= 0 && pi < N && pj < M) {								
						f = (f * 10LL) + (table[pi][pj] - '0');					
											
						pi += row_rate;
						pj += col_rate;
						
						if (perf.count(f)) ans = max(ans, (int) f);
					}			
				}				
			}
		}
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
