class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int p) {
        int count = 0;
        int i = 1;

        while(i < nums.size()) {
            int diff = abs(nums[i] - nums[i-1]);
            if(diff <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }

        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back();
        int ans = INT_MAX;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(nums, mid, p)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};