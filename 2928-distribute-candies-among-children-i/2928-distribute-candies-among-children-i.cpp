class Solution {
public:
    int distributeCandies(int n, int limit) {
        // Step 1: If n is greater than 3×limit, then it is not possible to distribute them among 3 children. So the function should return 0.
        if (n > 3*limit) 
            return 0;

        // Step 2: Find total number of ways to distribute the candies if step 1 limit satisfies and store in ans
        long ans = (n+2)*(n+1)/2;

        // Step 3: Then if (n>limit), we need to subtract the cases where one or more children receive more than the limit.
        if (n > limit)  
        ans -= 3*(n-limit+1)*(n-limit)/2;

        // Step 4: If (n-2 >= 2*limit), we need to add the cases where one or more children receive less than the limit.
        if (n-2 >= 2*limit) 
        ans += 3*(n-2*limit)*(n-2*limit-1)/2;

        return ans;
    }
};