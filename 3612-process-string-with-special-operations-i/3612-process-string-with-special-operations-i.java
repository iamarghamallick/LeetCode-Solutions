class Solution {
    public String processStr(String s) {
        String result = "";
        for(char c: s.toCharArray()) {
            if(c == '*') {
                if(result.length() > 0) {
                    result = result.substring(0, result.length() - 1);
                }
            } else if(c == '#') {
                result += result;
            } else if(c == '%') {
                result = new StringBuilder(result).reverse().toString();
            } else {
                result += c;
            }
        }
        return result;
    }
}