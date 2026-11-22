class Solution {
    public boolean checkString(String s) {
        int lastA = -1;
        int firstB = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'a') {
                lastA = i;
            } else if (firstB == -1 && s.charAt(i) == 'b') {
                firstB = i;
            }
        }

        return firstB == -1 || lastA < firstB;
    }
}