class Solution {
    public boolean hasSameDigits(String s) {
        int n = s.length();
        if(n == 2) {
            if(s.charAt(0) == s.charAt(1))
                return true;
            return false;
        }

        String str = "";
        for(int i=1; i<n; i++) {
            int n1 = s.charAt(i-1) - '0';
            int n2 = s.charAt(i) - '0';
            int sum = (n1 + n2) % 10;
            str += Integer.toString(sum);
        }

        return hasSameDigits(str);
    }
}