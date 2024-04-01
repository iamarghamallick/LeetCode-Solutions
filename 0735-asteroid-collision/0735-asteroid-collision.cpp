class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(arr[0]);
        
        for(int i=1; i<n; i++) {
            while(!st.empty() && (st.top() > 0) && (arr[i] < 0) && (st.top() < abs(arr[i])))
                st.pop();

            if(!st.empty() && (st.top() > 0) && (arr[i] < 0) && (st.top() == abs(arr[i])))
                st.pop();
            
            else if(!st.empty() && ((st.top() <= 0 && arr[i] <= 0) || (st.top()>0 && arr[i]>0) || (st.top()<0 && arr[i]>0)))
                st.push(arr[i]);
            
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