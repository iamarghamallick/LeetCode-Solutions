class Solution {
public:
    vector<pair<int, int>> toDigitPair(string nums) {
        vector<pair<int, int>> arr; // <digit, count>
        char curr = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == curr) count++;
            else {
                arr.push_back({curr - '0', count});
                curr = nums[i];
                count = 1;
            }
        }
        arr.push_back({curr - '0', count});
        return arr;
    }

    string createNewInt(vector<pair<int, int>> arr) {
        string newInt = "";
        for(int i=0; i<arr.size(); i++) {
            int digit = arr[i].first;
            int count = arr[i].second;

            newInt += to_string(count) + to_string(digit);
        }
        return newInt;
    }

    string countAndSay(int n) {
        if(n == 1) return "1";
        
        int count = 1;
        string res = createNewInt(toDigitPair("1"));
        while(++count < n) {
            res = createNewInt(toDigitPair(res));
        }
        return res;
    }
};