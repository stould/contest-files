vector<int> data;

vector<int> A, pos;
vector<int>::iterator it;
A.push_back(data[0]);

pos = vector<int>(data.size(), 0);
int n = data.size(), LIS = 1;

for (int i = 1; i < n; ++i) {
	it = lower_bound(A.begin(), A.end(), data[i]);
	pos[i] = (int)(it - A.begin());
	get_max(LIS, pos[i]);
	if (it == A.end()) {
		A.push_back(data[i]);
	} else {
		*it = data[i];
	}
 }
for (int i = n - 1; i >= 0; --i) {
	if (pos[i] == LIS) {
		A[LIS--] = data[i];
	}
 }
printf("%d\n-\n", (int)A.size());
for (int i = 0; i < A.size(); ++i) {
	printf("%d\n", A[i]);
 }
