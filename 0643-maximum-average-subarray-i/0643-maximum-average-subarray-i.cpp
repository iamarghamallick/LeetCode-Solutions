class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = k-1;
        int sum = 0;
        for(int k=i; k<=j; k++)
            sum += nums[k];
        
        double avg = (double)sum / k;
        
        i++; j++;
        while(j < nums.size()) {
            sum = sum - nums[i-1] + nums[j];
            avg = max(avg, (double)sum / k);
            i++; j++;
        }
        
        return avg;
    }
};