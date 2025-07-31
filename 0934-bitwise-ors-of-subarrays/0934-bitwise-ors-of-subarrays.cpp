class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, cur;
        cur.insert(0);

        for(int num : arr) {
            unordered_set<int> cur2;
            for(const auto& item: cur)
                cur2.insert(num | item);
            cur2.insert(num);
            cur = cur2;
            ans.insert(cur.begin(), cur.end());
        }

        return ans.size();
    }
};