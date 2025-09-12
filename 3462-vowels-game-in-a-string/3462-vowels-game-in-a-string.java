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

        return true;

        // at this point there are even # of vowels present in the string
        // alice should remove the substring of max length,
        // which should contain odd # of vowels,
        // left behind only one vowel with remaining other chars

        // int start = 0;
        // int end = n-1;
        // while(!isVowel(arr[start])) start++;
        // while(!isVowel(arr[end])) end--;
        // int startLen = end; // index '0' to 'end-1'
        // int endLen = n - 1 - start; // index 'start+1' to 'n-1'

        // if(startLen > endLen) {
        //     start = end;
        //     end = n-1;
        // } else {
        //     end = start;
        //     start = 0;
        // }

        // n = end - start + 1;

        // at this point there are two choises,
        // if more than two chars left (one vowel, others consonants),
        // Bob can choose one 
    }
}