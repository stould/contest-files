//Get median of a sequence in O(log(n))
int median_retrieve(void) {
	if (minHeap.empty() && maxHeap.empty()) return 0;
	
	if (minHeap.size() == maxHeap.size()) {
		return min(minHeap.top(), maxHeap.top());
	} else {
		if (minHeap.size() > maxHeap.size()) {
			return minHeap.top();
		} else {
			return maxHeap.top();
		}
	}
}

void median_insert(int x) {
	if (x > median_retrieve()) {
		minHeap.push(x);
	} else {
		maxHeap.push(x);
	}
	
	while (abs((int) (minHeap.size() - maxHeap.size())) > 1) {
		if (minHeap.size() > maxHeap.size()) {
			int tmp = minHeap.top();
			minHeap.pop();
			maxHeap.push(tmp);
		} else {
			int tmp = maxHeap.top();
			maxHeap.pop();
			minHeap.push(tmp);
		}
	}
}
