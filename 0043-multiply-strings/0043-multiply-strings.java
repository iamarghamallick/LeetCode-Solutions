class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        String ans = "";

        for (int i = 0; i < num2.length(); i++) {
            String res = multiply(num1, num2.charAt(i) - '0', num2.length() - i - 1);
            ans = sum(ans, res);
        }

        return ans;
    }

    private String multiply(String num, int digit, int pos) {
        String ans = "";
        int carry = 0;

        for (int i = num.length() - 1; i >= 0; i--) {
            int n = ((num.charAt(i) - '0') * digit) + carry;
            ans = Integer.toString(n % 10) + ans;
            carry = n / 10;
        }

        while (carry > 0) {
            ans = Integer.toString(carry % 10) + ans;
            carry /= 10;
        }

        while (pos > 0) {
            ans += "0";
            pos--;
        }

        return ans;
    }

    private String sum(String num1, String num2) {
        String ans = "";
        int carry = 0;

        int i = num1.length() - 1;
        int j = num2.length() - 1;

        while (i >= 0 || j >= 0) {
            if (i >= 0)
                carry += (num1.charAt(i) - '0');
            if (j >= 0)
                carry += (num2.charAt(j) - '0');
            ans = Integer.toString(carry % 10) + ans;
            carry /= 10;
            i--;
            j--;
        }

        while (carry > 0) {
            ans = Integer.toString(carry % 10) + ans;
            carry /= 10;
        }

        return ans;
    }
}