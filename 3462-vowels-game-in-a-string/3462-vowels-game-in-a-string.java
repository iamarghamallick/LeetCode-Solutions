class Solution {
    private boolean isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' ||
           c == 'o' || c == 'u')
            return true;
        
        return false;
    }

    public boolean doesAliceWin(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;
        int vowels = 0;

        for(char c : arr)
            if(isVowel(c)) vowels++;
        
        if(vowels == 0) return false;
        if(vowels % 2 != 0) return true;

        // at this point there are even # of vowels present in the string
        // alice should remove the substring of max length,
        // which contains odd # of vowels,
        // left behind only one vowel with remaining other chars
        // for Bobs turn -> there are two possibilities
        // 1. Only one vowel char is left - no move possible, Alice wins
        // 2. More than one char are left with one vowel,
        // so Bob can play by selecting the substring with zero vowels, 
        // then, in the next turn Alice select the entire string, 
        // leaving an empty string for Bob, so Alice wins in both senarios
    
        return true;
    }
}