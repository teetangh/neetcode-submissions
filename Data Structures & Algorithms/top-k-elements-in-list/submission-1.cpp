class Solution {
	struct Compare {
		bool operator()(pair<int, int> a, pair<int, int>b){
			if (a.second < b.second) {
				return true;
			}
			
			if (a.second == b.second && a.first < b.first){
				return true;
			}
			
			return false;
		}
	};
	public:
	vector<int> topKFrequent(vector<int> &arr, int k) {
		unordered_map<int, int> freq;
		for (int i = 0; i < arr.size() ; i++)
			freq[arr[i]]++;
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
		for (pair<int, int> p : freq) {
			pq.push(p);
		}
		
		vector<int> result;
		while (k-- && !pq.empty()) {
			int ele = pq.top().first;
			pq.pop();
			result.push_back(ele);
		}
		
		return result;
	}
};
