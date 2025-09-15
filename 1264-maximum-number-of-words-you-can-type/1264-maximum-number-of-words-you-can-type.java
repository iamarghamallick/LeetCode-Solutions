class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        String[] words = text.split(" ");
        boolean[] map = new boolean[26];
        char[] arr = brokenLetters.toCharArray();
        for(char c : arr) {
            map[c - 'a'] = true;
        }
        int count = 0;
        for(String word : words) {
            char[] ch = word.toCharArray();
            boolean flag = true;
            for(char c : ch) {
                if(map[c - 'a']) {
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
}