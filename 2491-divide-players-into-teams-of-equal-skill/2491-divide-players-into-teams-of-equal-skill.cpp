class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int left = 0, right = n - 1;
        int sum = skill[left] + skill[right];
        long long chem = 0;
        while(left < right) {
            if(skill[left] + skill[right] == sum)
                chem += (long long)skill[left] * skill[right];
            else
                return -1;
            left++; right--;
        }
        return chem;
    }
};