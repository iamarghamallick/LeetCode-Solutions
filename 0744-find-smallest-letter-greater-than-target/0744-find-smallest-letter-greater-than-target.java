class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        char ans = '{';
        for(int i=0; i<letters.length; i++) {
            if(letters[i] > target) {
                if(letters[i] < ans)
                    ans = letters[i];
            }
        }
        return ans == '{' ? letters[0] : ans;
    }
}