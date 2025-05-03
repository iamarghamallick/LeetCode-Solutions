class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        for(int target = 1; target <= 6; target++) {
            int rotateTop = 0, rotateBottom = 0;
            int flag = false;
            for(int i=0; i<tops.size(); i++) {
                if(tops[i] != target && bottoms[i] != target) {
                    flag = true;
                    break;
                }
                if(tops[i] != target)
                    rotateTop++;
                if(bottoms[i] != target)
                    rotateBottom++;
            }

            if(!flag)
                ans = min(ans, min(rotateTop, rotateBottom));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};