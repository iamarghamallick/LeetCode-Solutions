class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(int num : arr)
            freq[((num % k) + k) % k]++;
        for(int num : arr) {
            int rem = ((num % k) + k) % k;
            if(rem == 0) {
                if(freq[rem] % 2 == 1)
                    return false;
            } else if(freq[rem] != freq[k - rem])
                return false;
        }
        return true;
    }
};