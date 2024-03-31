class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    int maxVowels(string s, int k) {
        int i = 0, j = k-1;
        int maxCount = 0;
        
        for(int n=i; n<=j; n++)
            if(isVowel(s[n]))
                maxCount++;
        
        i++; j++;
        int count = maxCount;
        
        while(j < s.length()) {
            if(isVowel(s[i-1])) count--;
            if(isVowel(s[j]))   count++;
            
            maxCount = max(maxCount, count);
            i++; j++;
        }
        
        return maxCount;
    }
};