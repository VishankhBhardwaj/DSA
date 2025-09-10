class Solution {
public:
    int findmax(const vector<int>& piles) {
        int maxVal = INT_MIN;
        for (auto i : piles) {
            maxVal = std::max(maxVal, i);
        }
        return maxVal;
    }

    bool isValid(const vector<int>& piles, int mid, int h) {
        long long totalHours = 0; // Use long long to prevent overflow
        for (auto i : piles) {
            totalHours +=
                (i + mid - 1LL) / mid; // use 1LL to promote mid to long long
            if (totalHours > h)
                return false; // early exit if already exceeds h
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findmax(piles);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2; // safer than (low + high) / 2

            if (isValid(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
