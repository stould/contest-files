//Find string period
vector<int> prefix = KMP(S); //KMP Prefix function array
for (int i = 0; i < (int) prefix.size(); i++) {
	if (prefix[i] >= (int)  S.size() / 2) {
		period_len = i - prefix[i];		
	}
 }

