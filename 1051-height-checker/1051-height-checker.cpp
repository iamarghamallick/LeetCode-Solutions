class Solution {
public:
    int heightChecker(vector<int>& ht) {
        vector<int> arr = ht;
        sort(arr.begin(), arr.end());
        int count = 0;
        
        for(int i=0; i<ht.size(); i++)
            if(arr[i] != ht[i])
                count++;
        
        return count;
    }
};