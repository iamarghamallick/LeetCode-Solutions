class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int ans = INT_MIN;
        
        while(left < right) {
            int capacity = height[left] < height[right] ?
                           height[left] * (right-left) : height[right] * (right-left);
            ans = max(ans, capacity);
            
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return ans;
    }
};