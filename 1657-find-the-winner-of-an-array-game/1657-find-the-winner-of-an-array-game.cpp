class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxElem = arr[0];
        queue<int>  q;
        for(int i=1; i<n; i++) {
            maxElem = max(maxElem, arr[i]);
            q.push(arr[i]);
        }

        int curr = arr[0];
        int winStreak = 0;

        while(!q.empty()) {
            int oppo = q.front();
            q.pop();

            if(curr > oppo) {
                q.push(oppo);
                winStreak++;
            } else {
                q.push(curr);
                curr = oppo;
                winStreak = 1;
            }

            if(winStreak==k || curr==maxElem)
                return curr;
        }

        return -1;
    }
};