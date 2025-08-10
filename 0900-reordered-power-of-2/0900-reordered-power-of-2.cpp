class Solution {
public:
    void solve(vector<int> &nums, vector<int> &curr, int currNum,
                    vector<bool> &visited, unordered_set<int> &powerOfTwos,
                    vector<int> &ans) {
        if(curr.size() == nums.size()) {
            if(curr[0] != 0 && powerOfTwos.count(currNum)) 
                ans.push_back(currNum);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(ans.size() >= 1)
                return;

            if(visited[i])
                continue;

            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;
            
            visited[i] = true;
            curr.push_back(nums[i]);
            currNum = currNum * 10 + nums[i];

            solve(nums, curr, currNum, visited, powerOfTwos, ans);

            currNum /= 10;
            curr.pop_back();
            visited[i] = false;
        }
    }

    bool reorderedPowerOf2(int n) {
        unordered_set<int> powerOfTwos;
        long long powerOfTwo = 1;
        while(powerOfTwo <= (long long)pow(10, 9)) {
            powerOfTwos.insert(powerOfTwo);
            powerOfTwo *= 2;
        }

        vector<int> nums;
        while(n) {
            nums.push_back(n % 10);
            n /= 10;
        }

        sort(nums.begin(), nums.end());

        vector<int> curr;
        int currNum = 0;
        vector<bool> visited(nums.size(), false);
        vector<int> ans;

        solve(nums, curr, currNum, visited, powerOfTwos, ans);

        return ans.size() >= 1;
    }
};