class Solution {
public:
    long long calculateHours(const vector<int>& piles, int k) {
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + k - 1LL) / k;  // Use 1LL to avoid overflow
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int answer = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            long long hours = calculateHours(piles, mid);

            if (hours <= h) {
                answer = mid;       // Possible answer, try smaller m
                high = mid - 1;
            } else {
                low = mid + 1;      // Need more bananas/hour
            }
        }

        return answer;
    }
};
