class Solution {
public:
    int encrypt(int n) {
        int len = 0;
        int maxDigit = 0;
        while(n) {
            len++;
            maxDigit = max(maxDigit, n % 10);
            n /= 10;
        }
        
        int ans = 0;
        while(len--)
            ans = ans * 10 + maxDigit;
        
        return ans;
    }
    
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        
        for(int num : nums)
            sum += encrypt(num);
        
        return sum;
    }
};