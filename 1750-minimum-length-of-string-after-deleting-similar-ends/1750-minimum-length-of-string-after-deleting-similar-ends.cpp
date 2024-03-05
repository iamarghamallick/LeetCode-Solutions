class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if(n == 1)  return 1;
        
        int left = 0, right = n-1;
        while(left < right && s[left] == s[right]) {
            char c = s[left];
            while(left <= right && s[left] == c)    left++;
            while(right > left && s[right] == c)    right--;
        }
        
        return right - left + 1;
    }
};