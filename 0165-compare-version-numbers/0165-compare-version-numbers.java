class Solution {
    private int compare(int num1, int num2) {
        if(num1 > num2) return 1;
        if(num1 < num2) return -1;
        return 0;
    }

    public int compareVersion(String v1, String v2) {
        int n = v1.length();
        int m = v2.length();
        int i = 0;
        int j = 0;
        int num1 = 0;
        int num2 = 0;

        while(i < n || j < m) {
            while(i < n && v1.charAt(i) != '.') {
                num1 = num1 * 10 + (v1.charAt(i) - '0');
                i++;
            }
            
            while(j < m && v2.charAt(j) != '.') {
                num2 = num2 * 10 + (v2.charAt(j) - '0');
                j++;
            }
            
            int res = compare(num1, num2);
            if(res != 0)
                return res;
            
            i++; j++;
            num1 = 0; num2 = 0;
        }

        return 0;
    }
}