class Solution {
    int getDaysTaken(vector<int>& weights, int capacity) {
        int days = 0;

        int current = 0;
        for (auto weight : weights) {
            if (weight + current <= capacity) {
                current += weight;
            } else {
                days += 1;
                current = weight;
            }
        }
        return current != 0 ? days + 1 : days;
    }

   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int daysTaken = getDaysTaken(weights, mid);
            if (daysTaken <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};