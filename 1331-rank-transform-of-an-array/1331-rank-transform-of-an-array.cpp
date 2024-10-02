class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() <= 0)
            return {};
        
        vector<int> a(arr.begin(), arr.end());
        sort(a.begin(), a.end());
        unordered_map<int, int> rank;
        int currRank = 1;
        rank[a[0]] = 1;
        
        for(int i=1; i<a.size(); i++)
            if(rank[a[i]] == 0)
                rank[a[i]] = ++currRank;

        for(int i=0; i<arr.size(); i++)
            arr[i] = rank[arr[i]];
        
        return arr;
    }
};