class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long ans = 0;
        sort(arr.begin(), arr.end());
        int dec = 0;
        for(int i=0; i<n && i<k; i++) {
            ans += (arr[n-1-i] - dec) > 0 ? (arr[n-1-i] - dec) : 0;
            dec++;
        }
        
        return ans;
    }
};