class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        String ans = "";
        for(String word: words) {
            int weight = 0;
            for(char c: word.toCharArray()) {
                weight += weights[c - 'a'];
            }
            weight %= 26;
            ans += (char) ((25 - weight) + 97);
        }
        return ans;
    }
}