class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;

        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<short>> dp(m+1,vector<short>(n+1));
        vector<vector<short>> up(m,vector<short>(n,1));
        vector<vector<short>> down(up);

        for(int i=m-1; ~i; i--)
            for(int j=n-1; ~j; j--) 
                dp[i][j] = matrix[i][j]=='1' ? dp[i][j+1] + 1 : 0;

        stack<int> st;
        for(int j=0; j<n; j++) {
            st = stack<int>();
            for(int i=0;i<m;i++) {
                while(st.size() && dp[st.top()][j] >= dp[i][j])
                    st.pop();

                up[i][j] = i-(st.size()?st.top():-1);
                st.push(i);
            }

            st = stack<int>();
        
            for(int i=m-1; ~i; i--) {
                while(st.size() && dp[st.top()][j] >= dp[i][j]) 
                    st.pop();
                
                down[i][j]=(st.size()?st.top():m)-i;
                st.push(i);
            }            
        }

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans = max(ans,dp[i][j] * (up[i][j]+down[i][j]-1));
        
        return ans;
    }
};