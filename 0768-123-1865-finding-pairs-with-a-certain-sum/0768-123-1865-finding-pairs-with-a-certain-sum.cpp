class FindSumPairs {
public:
    vector<int> a1, a2;
    unordered_map<int, int> map;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a1 = vector<int> (nums1.begin(), nums1.end());
        a2 = vector<int> (nums2.begin(), nums2.end());
        map = unordered_map<int, int>();
        for(int num : a2)
            map[num]++;
    }
    
    void add(int index, int val) {
        map[a2[index]]--;
        a2[index] += val;
        map[a2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;

        for(int i=0; i<a1.size(); i++) {
            ans += map[tot - a1[i]];
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */