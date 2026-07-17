class Solution {
    int hoursTakenToEatPile(vector<int>& piles, int k) {
        int hours = 0;
        for (auto pile : piles) {
            if (pile % k == 0) {
                hours += pile / k;
            } else {
                hours += (pile / k) + 1;
            }
        }
        cout << hours << endl;
        return hours;
    }

   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int hoursTaken = hoursTakenToEatPile(piles, mid);
            if (hoursTaken <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
