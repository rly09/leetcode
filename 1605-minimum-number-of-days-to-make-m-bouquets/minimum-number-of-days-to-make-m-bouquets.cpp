class Solution {
public:
    // Helper function to check if it's possible to make m bouquets by 'day'
    bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0, flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // Reset because we need adjacent flowers
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        if (total > bloomDay.size()) return -1;  // Not enough flowers

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, mid, m, k)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};
