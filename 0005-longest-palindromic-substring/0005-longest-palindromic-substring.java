class Solution {
    public boolean isPalindrom(int left, int right, String s) {
        while(left <= right) {
            if(s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++; right--;
        }
        return true;
    }
    public String longestPalindrome(String s) {
        int n = s.length();
        for(int i=n; i>0; i--) {
            for(int j=0; j<=n-i; j++) {
                if(isPalindrom(j, j+i-1, s)) 
                    return s.substring(j, j+i);
            }
        }
        return "";
    }
}