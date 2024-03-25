class Solution {
public:
    // Function to find minimum number of attempts needed in 
    // order to find the critical floor.
    
    // // Approch1 : Only Recursion
    // int solve(int e, int f) {
    //     // Base Cases
    //     if(f == 1)    return f;
    //     if(e == 1)  return f;
        
    //     int ans = INT_MAX;
        
    //     // Next Logic
    //     for(int k=1; k<=f; k++) {
    //         int tempAns = 1 + max(solve(e-1, k-1), solve(e, f-k));
    //         ans = min(ans, tempAns);
    //     }
        
    //     return ans;
    // }
    
//     // Approch2 : Recursion with Memoization
//     int dp[101][10001];
    
//     int solve(int e, int f) {
//         // Base Cases
//         if(f == 0 || f == 1)    return f;
//         if(e == 1)  return f;
        
//         int ans = INT_MAX;
        
//         if(dp[e][f] != -1)
//             return dp[e][f];
        
//         // Next Logic
//         for(int k=1; k<=f; k++) {
//             int tempAns = 1 + max(solve(e-1, k-1), solve(e, f-k));
//             ans = min(ans, tempAns);
//         }
        
//         return dp[e][f] = ans;
//     }
    
    // Approch3 : Recursion with Memoization and Binary Search Technique
    int dp[101][10001];
    
    int solve(int e, int f) {
        // Base Cases
        if(f == 0 || f == 1)    return f;
        if(e == 1)  return f;
        
        int ans = INT_MAX;
        
        if(dp[e][f] != -1)
            return dp[e][f];
        
        // Next Logic for binary search technique 
        int low = 0, high = f;
        while(low <= high) {
            int mid = (low + high) / 2;
            
            int left = solve(e-1, mid-1);
            int right = solve(e, f-mid);
            
            int tempAns = 1 + max(left, right);
            
            //since we need more temp value in worst case, so need to go above
            if(left < right) 
                low = mid + 1;
            else 
                high = mid - 1;     //move to the downward
            
            ans = min(ans, tempAns);
        }
        
        return dp[e][f] = ans;
    }
    
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
};