class Solution {
    public int maxNumberOfBalloons(String text) {
        HashMap<Character, Integer> map = new HashMap<>();
        for(char c: text.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        String word = "balloon";
        map.put('l', map.getOrDefault('l', 0) / 2);
        map.put('o', map.getOrDefault('o', 0) / 2);
        int ans = Integer.MAX_VALUE;
        for(char c: word.toCharArray()) {
            ans = Math.min(ans, map.getOrDefault(c, 0));
        }
        return ans;
    }
}