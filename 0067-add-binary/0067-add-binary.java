class Solution {
    public String addBinary(String a, String b) {
        String ans = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while(i >= 0 || j >= 0 || carry == 1) {
            int a1 = i >= 0 ? a.charAt(i) - '0' : 0;
            int b1 = j >= 0 ? b.charAt(j) - '0' : 0;
            int sum = a1 + b1 + carry;
            ans = Integer.toString(sum % 2) + ans;
            carry = sum / 2;
            i--; j--;
        }
        return ans;
    }
}