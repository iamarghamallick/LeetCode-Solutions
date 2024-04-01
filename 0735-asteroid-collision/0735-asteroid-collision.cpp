class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(arr[0]);
        
        // main logic
        for(int i=1; i<n; i++) {
            // 1st case to handle ->
            // If the previous asteroid is +ve valued and present one is -ve valued,
            // i.e. they will collide
            // Ans also if the present asteroid is larger, previous one will be exploded.
            while(!st.empty() && (st.top() > 0) && (arr[i] < 0) && (st.top() < abs(arr[i])))
                st.pop();

            // 2nd case -> 
            // If the previous asteroid is +ve valued and present one is -ve valued,
            // i.e. they will collide
            // Now, if the prev and present asteroid is of same size
            // i.e., both will be exploded, so pop and proceed to the next
            if(!st.empty() && (st.top() > 0) && (arr[i] < 0) && (st.top() == abs(arr[i])))
                st.pop();
            
            // 3rd case ->
            // Check the conditions of NO COLLISION
                // 1. prev and curr asteroid is both -ve valued, i.e., both moving towards left
                // 2. prev and curr asteroid is both +ve valued, i.e., both moving towards right
                // 3. prev asteroid is -ve valued and curr asteroid is +ve valued, i.e., moving to opposite direction
            // In these cases we just need to push the present asteroid into the stack and proceed to the next
            else if(!st.empty() && ((st.top() <= 0 && arr[i] <= 0) || (st.top() > 0 && arr[i] > 0) || (st.top() < 0 && arr[i] > 0)))
                st.push(arr[i]);
            
            // Otherwise if the stack is empty, just push the present asteroid into the stack
            else if(st.empty())
                st.push(arr[i]);
                              
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};