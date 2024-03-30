class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int a=0; a<n; a++)
            for(int b=a+1; b<n; b++)
                for(int c=b+1; c<n; c++)
                    for(int d=c+1; d<n; d++)
                        if(nums[a] + nums[b] + nums[c] == nums[d])
                            count++;
                        
        return count;
    }
//     int countQuadruplets(vector<int>& nums) {
//         int count = 0;
//         int n = nums.size();
//         vector<int> map(310, 0);
        
//         // Start from the second-to-last element and go backwards, as this is the 'b' in the quadruplet.
//         for (int b=n-3; b>0; b--) {
//             // 'c' is always to the right of 'b', so start from 'b + 1'.
//             for (int c=b+1; c<n-1; c++) {
//                 // 'd' is always to the right of 'c', so start from 'c + 1'.
//                 for (int d=c+1; d<n; d++) {
//                     if (nums[d] - nums[c] >= 0) {
//                         // Increment the frequency of this particular difference.
//                         map[nums[d] - nums[c]]++;
//                     }
//                 }
//             }
//             // Now looking for 'a' which is to the left of 'b'.
//             for (int a=0; a<b; a++) {
//                 // If a sum of nums[a] and nums[b] happened to be the difference
//                 // previously recorded, it contributes to the total count.
//                 count += map[nums[a] + nums[b]];
//             }
//             // Reset the frequency array for the next iteration.
//             // This ensures that we only count the differences relevant to the current 'b'.
//             fill(map.begin(), map.end(), 0);
//         }
        
//         return count;
//     }
};