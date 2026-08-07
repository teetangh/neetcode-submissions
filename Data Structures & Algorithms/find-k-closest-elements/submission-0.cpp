class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp = [x](int a, int b) {
            if (abs(x - a) < abs(x - b))
                return false;
            else if ((abs(x - a) == abs(x - b)) and (a < b))
                return false;
            else
                return true;
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (auto t : arr) pq.push(t);

        vector<int> result;
        int count = 0;
        while (!pq.empty()) {
            auto el = pq.top();
            pq.pop();

            result.push_back(el);
            count++;
            if (count == k) break;
        }
        sort(result.begin(), result.end());
        return result;
    }
};