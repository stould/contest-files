//Find string period
int stringPeriod(string arg) {
	int ori_len = (int) arg.size();
	arg = arg + arg;
	
	vector<int> prefix = KMP(arg);
	int ans = (int) arg.size();
	
	for (int i = 0; i < (int) prefix.size(); i++) {
		if (prefix[i] >= ori_len) {
			ans = i - prefix[i];
			break;
		}
	}
	return ans;
}
